#!/bin/bash

rsync -av --include="*/" --include="*.[h|c]" --exclude="*" ./gini5/ comp535:~/gini5/

