from selenium import webdriver
from time import sleep
import requests
import ddddocr
from webdriver_manager.chrome import ChromeDriverManager
import base64
import requests
username = ""
password = ""
url = "https://signin.fcu.edu.tw/clockin/login.aspx"
driver = webdriver.Chrome("/Users/Public/code/chromedriver")
driver.get(url)
driver.find_element("id","LoginLdap_UserName").send_keys(username)
driver.find_element("id","LoginLdap_Password").send_keys(password)
driver.find_element("id","LoginLdap_LoginButton").click()
driver.find_element("id","ButtonClassClockin").click()
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
driver.find_element("id","validateCode").send_keys(res)
driver.find_element("id","Button0").click()
sleep(60)