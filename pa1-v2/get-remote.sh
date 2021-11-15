#!/bin/bash

file=$1

echo "Dry run?"
select yn in "Yes" "No"; do
	case $yn in 
		Yes ) options="avn"; break;;
		No ) options="av"; break;;
	esac
done

rsync "-${options}" --include="*/" --include="${file}.[h|c]" --exclude="*" --prune-empty-dirs comp535vm:~/gini5 ./
