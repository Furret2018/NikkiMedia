---
title: "R RStudio and Git"
output: html_document
---


  **R** is installed on desktop/RDIR, now is moved to `C:\temp\RDIR\`
  
  **RStudio** installed on desktop/RSDIR, now 1s moved to `C:\temp\RSDIR\`    
  RStudio path : `C:\temp\RSDIR\bin\rstudio.exe`
  
  **Git** is using Portable version, now is moved to `C:\temp\PortableGit\`



Config Git with RStudio:
------------------------

## Choose the R version:

>  RStudio Menu::Tools > Global options > General::R version:

- Press button change, and it will popup dialog window "Choose R Installation"
- Select "Choose a specific version of R:"
- Select an item in the list. such as `[64-bit] C:\temp\RDIR`

Note:     
If no options in list, press "Browse..." to specify the R installation folder, then you can choose the R version.      
You may need to reboot RStudio for take effort.

## Specify Git.exe

>  RStudio Menu::Tools > Global options > Git/SVN::Git executable

`C:/temp/PortableGit/bin/git.exe`




https://support.rstudio.com/hc/en-us/articles/200532077?version=1.2.5001&mode=desktop





C:\Users\gliu1586\AppData\Local\Programs\avaya-spaces\Avaya Spaces.exe