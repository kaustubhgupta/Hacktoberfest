
from distutils.dir_util import copy_tree

# Copy an entire directory tree src to a new location dst. 
# If src is not a directory, it raises DistutilsFileError. If dst does not exist, it is created with mkpath(). 
# The end result of the copy is that every file in src is copied to dst.

def copyToFilePath(src, dst):
	try:
		copy_tree(src, dst)
		print("Files from source path ,copied to destination path successfully!")
	except:
		print("Exception caught: no directory found at source path!")


# take command line input
print("input source file path : to be copied from")
src = input()

print("input destination file path : to copy at")
dst = input()

# copy src path files and folders to dst path
copyToFilePath(src, dst)