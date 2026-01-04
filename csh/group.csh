#/usr/bin/env tcsh

set primary=`groups | awk '{print $1}'`
echo $primary

if ( $primary  == "rhphenix" ) then
  echo $primary
else
  echo bad
endif 
