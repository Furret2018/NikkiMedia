print(osVersion)    # print the system verison
dir <- getwd()      # print the work directory
print(dir)
class(dir)
typeof(dir)


mydesktop <- "C:\\Users\\gliu1586\\Desktop"
setwd(mydesktop)

getwd()


# R lang is case senstive
####################################################################

# set the working directory to C:\temp\
cat ("Now, the working directory is ", getwd())

dir<- "C:\\temp\\"
if (dir.exists(dir)){
  setwd(dir)
  cat("Working dirtory now is :", dir)
}


# create directory 
gitHubRepository <- "GitHubRepository"
gitHubRepository <- paste0(dir, tolower(gitHubRepository))
gitHubRepository

########################################################
cat("Now, Try to create directory", gitHubRepository, "\n")
if (dir.exists(gitHubRepository)){
  cat(gitHubRepository, "already exists! \n")
}else{
  dir.create(gitHubRepository)
}

########################################################
createDir <- function(dirname){
  if (dir.exists(dirname)) cat(dirname, "already exists! \n")
  else dir.create(dirname)
}

createDir(gitHubRepository)


# Delete directory
gitHubRepository
file.remove(gitHubRepository)

file.exists(gitHubRepository)
file.remove(gitHubRepository)

filename <- "c:/temp/1.txt"
file.exists(filename)
file.remove(filename)


system.file()


###############################################
# List dir or file under specified dir

x <- list.dirs(dir, recursive = FALSE)
print(x)


x <- list.files(dir)
print(x)
typeof(x)

length(x)
x[1]




