#!/bin/bash

echo "Restoring remote gini from backup.."
rsync -avz --delete comp535vm:~/gini5.bak comp535vm:~/gini5/ 
