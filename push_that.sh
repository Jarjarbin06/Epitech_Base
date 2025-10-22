#!/bin/bash
read -p "Commit name : " COM_NAME
git add -A
git commit -m "$COM_NAME"
git branch -M main
git remote add origin git@github.com:Jarjarbin06/Epitech_Base.git
git push -u origin main
