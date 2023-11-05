#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: identifica faixas de endereços e reescreve log
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2023-09-08 - arquivo criado 
#---------------------------------------------------------------------
# Parâmetros	: $1 - arquivo de endereços ordenado sem repetição
#		: $2 - arquivo de log a ser reescrito
#---------------------------------------------------------------------

BEGIN{
  currstart = -1
  currend = -1
  tamword = 8
  numranges=0
}
# processing first file, unique addresses
(ARGIND==1){
  # handle the first line
  if (currstart == -1){ currstart = $1 }
  if (currend == -1){ currend = $1 }
  # there is a address gap. insert new range and reinitialize 
  if ($1>currend+tamword){
    startrange[numranges]=currstart;
    endrange[numranges]=currend;
    numranges++;
    lastrange=FNR
    currstart = $1
    currend = $1
  } else {
    # just update current range
    currend = $1
  }
}
# processing second file, log to be fixed
(ARGIND==2){
  # if it is the first line of the 2nd file, finish the process of the 1st
  if (FNR==1){
    # there maybe a range that was not created.
    if (lastrange<NR-1){
      startrange[numranges]=currstart;
      endrange[numranges]=currend;
      numranges++;
    }
    # set the parameters for address rewriting
    baserange[0] = 0;
    addrcount = 0 
    # for debugging
    # print startrange[0], endrange[0], baserange[0], addrcount
    for (i=1; i<numranges; i++){
      addrcount+=endrange[i-1]-startrange[i-1];  
      baserange[i]=addrcount+tamword;
      # for debugging
      #print startrange[i], endrange[i], baserange[i],addrcount
    }
  }
  # log rewriting
  # E or L event
  if (NF == 7){
    addr = $6    
    for (i=0; i<numranges; i++){
      # check the address range
      if ((addr>=startrange[i])&&(addr<=endrange[i])){
        # write the first 5 fields
        for (j=1; j<6; j++){
  	  printf("%s ",$j)
        }
        # write fixed address and last field
        printf("%d %d\n", addr-startrange[i]+baserange[i], $7)
      }
    } 
  } else {
    # remaining events
    print $0
  }
}

END{
}
