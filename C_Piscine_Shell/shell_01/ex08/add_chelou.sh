#! /bin/sh
echo $FT_NBR1 + $FT_NBR2 | sed -e 's/\\/1/g' -e 's/?/3/g' -e 's/!/4/g' -e "s/\'/0/g" -e "s/\"/2/g" | tr "mrdoc" "01234" | xargs echo "ibase=5; obase=23;" | bc | tr "0123456789ABC" "gtaio luSnemf"
