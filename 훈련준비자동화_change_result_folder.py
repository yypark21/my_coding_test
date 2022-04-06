#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os 
import shutil
import xml.etree.ElementTree as ET

path ='./images/'
new_path = './annotations/xmls/'

if not os.path.exists(new_path):
    os.mkdir(new_path)

files = os.listdir(path)
f = open("./annotations/trainval.txt", 'w')
for file in files:
    if 'xml' in file:
        writeFileName = file.split(".")[0]
        shutil.copy(path+file, new_path+file)
        f.write(writeFileName)
        f.write("\n")
f.close()


print('.xml files have been copied in new folder!')
print('Making record file success!!')

files = os.listdir(new_path)
class_name = []

for file in files:
    if '.xml' in file:
        tree = ET.parse(path+file)
        root = tree.getroot()
        for child in root:
            if 'object' in child.tag:
                if child[0].text not in class_name:
                    class_name.append(child[0].text)

class_name.sort()

with open("./annotations/label_map.pbtxt", 'w') as f:
    for i in range(len(class_name)):
        f.write('item {\n  id: %d\n  '%(i+1)+'name: \'%s\'\n}\n'%class_name[i])


print('Making label_map.pbtxt file success!!')
