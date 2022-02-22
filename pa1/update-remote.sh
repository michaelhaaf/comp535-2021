#!/bin/bash

echo "Dry run?"
select yn in "Yes" "No"; do
	case $yn in 
		Yes ) options="avn"; break;;
		No ) options="av"; break;;
	esac
done

rsync "-${options}" --include="*/" --include="*.[h|c]" --exclude="*" ./gini5/ comp535vm:~/gini5/

