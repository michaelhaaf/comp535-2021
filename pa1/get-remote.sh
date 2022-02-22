#!/bin/bash

rsync -avn --include="*/" --include="cli.[h|c]" --exclude="*" --prune-empty-dirs comp535vm:~/gini5 ./
