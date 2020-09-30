import os
print("Incrementals are made using target zips which are found under out/target/product/device/obj/PACKAGING/target_files_intermediates") 
old_zip=input("Enter old target file path: ")
new_zip=input("Enter new target file path: ")
print("Generating incremental package")
try:
		filecheck=open("generator.sh")
		filecheck.close()
except:
    code="./build/make/tools/releasetools/ota_from_target_files  --block -i old new incremental.zip"
    saveFile2=open("generator.sh",'w')
    saveFile2.write(str(code))
    saveFile2.close()
fin = open("generator.sh", "rt")
data = fin.read()
data = data.replace('old', old_zip)
fin.close()
fin = open("generator.sh", "wt")
fin.write(data)
fin.close()
fin = open("generator.sh", "rt")
data = fin.read()
data = data.replace('new', new_zip)
fin.close()
fin = open("generator.sh", "wt")
fin.write(data)
fin.close()
os.system("chmod a+x generator.
