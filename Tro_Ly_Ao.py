#import speech_recogniton
import pyttsx3
from datetime import date
from datetime import datetime

'''==========NGHE=========='''
#Khởi tạo
robot_ear = speech_recognition.Recognizer()
robot_mouth = pyttsx3.init()
robot_brain = ""

#Dùng vòng lặp
while True:
    with speech_recognition.Microphone() as mic:  # khi nói xong mic sẽ tự động tắt
        # mic = speech_recognition.Microphone()  #mic bật liên tục gây ra lỗi
        print("Robot: I am listening to what you say!")
        print("Let's talk something!")
        audio = robot_ear.listen(mic)

    print("Robot: ...")
    try:
        you = robot_ear.recognition_google(audio)
    except:
        you = ""

    print("You: ", you)

    '''============HIỂU - AI============'''
#Xử lí ngôn ngữ tự nhiên:
    if you == "":
        robot_brain = "Sorry! I can not hear you, please try again! "
    elif "Hello" in you:
        robot_brain = "Hello! Nice to talk with you!"
    elif "today" in you:
        today = date.today()
        robot_brain = today.strftime("%B %d, %Y")
    elif "time" in you:
        now = datetime.now()
        robot_brain = now.strftime("%H hour %M minutes %s seconds")
    elif "American president" in you:
        robot_brain = "Donald Trump"
    elif "handsome" in you:
        robot_brain = "You are so handsome!"
    elif "bye" in you:
        robot_brain = "Goodbye! See you again!"
        "===========Nói============"
        print("Robot: ", robot_brain)
        robot_mouth.say(robot_brain)
        robot_mouth.runAndWait()
        break
    else:
        robot_brain = "I can not hear what you say."

"""Cài đặt thư viện: 
    + pip install pyttsx3
    + pip install pyaudio 
       (nếu không được: pip install pipwin  ---> pipwin install pyaudio
    + nếu không có module pythoncom thì: pip install pipwin32
    
    """