#!/bin/bash
read -p "Commit name : " COM_NAME
git add -A
git commit -m "$COM_NAME"
git branch -M main
git remote add origin SSH //SSH to be replaced with ssh key to your repository
git push -u origin main
