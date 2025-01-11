from ctypes.wintypes import WORD
import datetime
from distutils.cmd import Command
from email import message_from_string
from imaplib import Commands
from pprint import pprint
from playsound import playsound
import pyttsx3
import speech_recognition as sr
import webbrowser 
import pywhatkit
import wikipedia
import os
import pyautogui
import keyboard
import pyjokes
import pydictionary as diction

Assistant = pyttsx3.init('sapi5')
voices = Assistant.getProperty('voices')
Assistant.setProperty('voice', voices[2].id)
Assistant.setProperty('rate',170)

def speak(audio):
    print("  ")
    Assistant.say(audio)
    print("  ")
    print(f" : {audio}")

    Assistant.runAndWait()
  

def takecommand():
    command = sr.Recognizer()
    with sr.Microphone() as source:
        print("listening.....")
        command.pause_threshold = 1
        audio = command.listen(source)

        try:
            print("Recognizing....")
            query = command.recognize_google(audio,language='en-in')
            print(f"You said : {query}")

        except Exception as Error:
            return "none"
        
        return query.lower()


while True:

        query = takecommand()
            
        if 'up page' in query:
            keyboard.press_and_release('Page Up')
        
        elif 'nap time' in query:
            speak("You can call me any time...")
            break