import xml.etree.ElementTree as ET
import glob
import copy

for targetDir in sorted(glob.glob('./*.xml')):
    print(targetDir)
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
        tree.write(targetDir)

    
    
    # anno.write(targetDir)

# object 가 있다면 복사해서 각 xmin ymin xmax ymax 에 -3 을 해 준 후 write
