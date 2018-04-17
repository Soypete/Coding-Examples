import os

#function
def rename_files():
    #(1) get file names from a folder
    file_list = os.listdir("/Users/peteedv9/Documents/GitHub/python/rename_files/prank")
    print(file_list)
    #print('hi')
    saved_path = os.getcwd()
    print("current Working Directory os "+saved_path)
    os.chdir("/Users/peteedv9/Documents/GitHub/python/rename_files/prank")
    
    #(2) for each file, rename filename
    for file_name in file_list:
        os.rename(file_name,file_name.translate(None, "0123456789"))

    os.chdir(saved_path)
    print("files changed")

rename_files()
    
