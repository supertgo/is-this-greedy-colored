#!/usr/bin/bash
#---------------------------------------------------------------------
# Arquivo	: fixaddr.csh
# Conteúdo	: ajustar endereços obtidos com memlog 
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2023-09-08 - arquivo criado
#---------------------------------------------------------------------
# Parâmetros	: $1 is the inputfile containing the log
#		: $2 is the output directory
#---------------------------------------------------------------------

gawk -f fixaddr/getaddr.awk $1 | sort -nu > $2/$1.addr
gawk -f fixaddr/genfaixas.awk $2/$1.addr $1 > $2/$1.fixed

