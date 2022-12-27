from selenium import webdriver
from time import sleep
import requests
import ddddocr
from webdriver_manager.chrome import ChromeDriverManager
import base64
import requests
while(1):
    username = "帳號"
    password = "密碼"
    url = "網址"
    driver = webdriver.Chrome("chromedriver")
    driver.get(url)
    driver.find_element("id","??").send_keys(username)
    driver.find_element("id","??").send_keys(password)
    img_base64 = driver.execute_script("""
        var ele = arguments[0];
        var cnv = document.createElement('canvas');
        cnv.width = ele.width; cnv.height = ele.height;
        cnv.getContext('2d').drawImage(ele, 0, 0);
        return cnv.toDataURL('image/jpeg').substring(22);    
        """, driver.find_element("xpath","//*[@id='form1']/div[3]/img[2]"))
    with open("captcha.png", 'wb') as image:
        image.write(base64.b64decode(img_base64))
    ocr = ddddocr.DdddOcr()
    with open('captcha.png', 'rb') as f:
        img_bytes = f.read()
    res = ocr.classification(img_bytes)
    driver.find_element("id","??").send_keys(res)