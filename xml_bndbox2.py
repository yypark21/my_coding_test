import xml.etree.ElementTree as ET
import glob
import copy
import os

for targetDir in sorted(glob.glob('./*.xml')):

    xml_file = open((targetDir), 'rt', encoding='UTF8')
    anno = ET.parse(xml_file)
    annotation = anno.getroot()

    for xy in annotation.findall('object'):
        copy_xy = copy.deepcopy(xy)
        
        copy_xy[4][0].text = '{}'.format(int(copy_xy[4][0].text)-3)
        copy_xy[4][1].text = '{}'.format(int(copy_xy[4][1].text)-3)
        copy_xy[4][2].text = '{}'.format(int(copy_xy[4][2].text)-3)
        copy_xy[4][3].text = '{}'.format(int(copy_xy[4][3].text)-3)
        
        annotation.append(copy_xy)
        tree = ET.ElementTree(annotation)
        # tree.write(targetDir) # 파일 이름 그대로
        
        file_path = os.path.splitext(targetDir)[0]
        tree.write(file_path+'new.xml')

    
    
    # anno.write(targetDir)

# object 가 있다면 복사해서 각 xmin ymin xmax ymax 에 -3 을 해 준 후 write
