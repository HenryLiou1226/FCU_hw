from selenium import webdriver
from time import sleep
import requests
import ddddocr
from webdriver_manager.chrome import ChromeDriverManager
import base64
while(1):
    username = "學號"
    password = "NID密碼"
    url = "https://course.fcu.edu.tw/Login.aspx"
    driver = webdriver.Chrome("/Users/Public/code/chromedriver")
    driver.get(url)
    img_base64 = driver.execute_script("""  
        var ele = arguments[0];
        var cnv = document.createElement('canvas');
        cnv.width = ele.width; cnv.height = ele.height;
        cnv.getContext('2d').drawImage(ele, 0, 0);
        return cnv.toDataURL('image/jpeg').substring(22);    
        """, driver.find_element("xpath","//*[@id='ctl00_Login1_Image1']"))
    with open("captcha.png", 'wb') as image:
        image.write(base64.b64decode(img_base64))
    ocr = ddddocr.DdddOcr()
    with open('captcha.png', 'rb') as f:
        img_bytes = f.read()
    res = ocr.classification(img_bytes)
    driver.find_element("id","ctl00_Login1_UserName").send_keys(username)
    driver.find_element("id","ctl00_Login1_Password").send_keys(password)
    driver.find_element("id","ctl00_Login1_vcode").send_keys(res)
    driver.find_element("id","ctl00_Login1_LoginButton").click()
    driver.find_element("id","ctl00_MainContent_TabContainer1_tabCourseSearch_wcCourseSearch_tbSubID").send_keys(2769)
    driver.find_element("id","ctl00_MainContent_TabContainer1_tabCourseSearch_wcCourseSearch_btnSearchOther").click()
    driver.find_element("id","ctl00_MainContent_TabContainer1_tabCourseSearch_wcCourseSearch_gvSearchResult_ctl02_btnAdd").click()
    driver.find_element("id","ctl00_MainContent_TabContainer1_tabCourseSearch_wcCourseSearch_lbtnGoToSelectedTab").click()
    driver.find_element("id","ctl00_MainContent_TabContainer1_tabSelected_gvWishList_ctl02_btnAdd").click()
    sleep(10)
    break