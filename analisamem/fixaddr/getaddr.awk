#---------------------------------------------------------------------
# Arquivo	: getaddr.awk 
# Conteúdo	: cria um arquivo separado com endereços E e L 
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2023-09-08 - arquivo criado
#---------------------------------------------------------------------

(($1=="E") || ($1=="L")){print $6}
