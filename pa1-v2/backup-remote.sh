#!/bin/bash

echo "Backing up remote gini..."
rsync -avz comp535vm:~/gini5/ comp535vm:~/gini5.bak
