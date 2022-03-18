#-*-coding:utf-8-*-

import os
from PIL import Image
import glob
from zipfile import ZipFile

def unzip_files(Dir):
    zip_files = glob.glob(os.path.join(Dir,"**" ,"*.zip"), recursive=True)
    for zip_file in zip_files:
        with ZipFile(zip_file, "r") as zip_ref:
            zipInfo = zip_ref.infolist()
            for member in zipInfo:
                member.filename = member.filename.encode('cp437').decode('euc-kr', 'ignore')
                zip_ref.extract(member, Dir)

def main():
    print ('Converting BMP to JPG in ' + os.getcwd())
    unzip_files(os.getcwd())
    for f in os.listdir(os.getcwd()):
        name, ext = os.path.splitext(f)
        if ext.lower() == ".bmp":
            outfile = name + ".jpg"
            Image.open(f).save(outfile)
            os.remove(f) # 기존 파일 삭제
    print ('Done.')

if __name__ == "__main__":
    main()
