#include "esp_camera.h"
#include <WiFi.h>
#include <Servo.h>

#define SERVO_PIN 13       // Pin connected to servo motor
#define CAMERA_MODEL_AI_THINKER // ESP32-CAM model

// Camera pins configuration (for AI Thinker model)
#if defined(CAMERA_MODEL_AI_THINKER)
  #define PWDN_GPIO_NUM     32
  #define RESET_GPIO_NUM    -1
  #define XCLK_GPIO_NUM      0
  #define SIOD_GPIO_NUM     26
  #define SIOC_GPIO_NUM     27
  #define Y9_GPIO_NUM       35
  #define Y8_GPIO_NUM       34
  #define Y7_GPIO_NUM       39
  #define Y6_GPIO_NUM       36
  #define Y5_GPIO_NUM       21
  #define Y4_GPIO_NUM       19
  #define Y3_GPIO_NUM       18
  #define Y2_GPIO_NUM        5
  #define VSYNC_GPIO_NUM    25
  #define HREF_GPIO_NUM     23
  #define PCLK_GPIO_NUM     22
#endif

Servo myServo;

void startCameraServer();

void setup() {
  Serial.begin(115200);
  
  // Initialize the servo motor
  myServo.attach(SERVO_PIN);
  myServo.write(0); // Initial position (lock)

  // Camera configuration
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG; 

  if(psramFound()){
    config.frame_size = FRAMESIZE_QVGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_QVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

  // Initialize the camera
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  startCameraServer();

  Serial.println("Camera Ready! Use 'http://<your-esp32-ip-address>' to connect");

  // Optionally connect to WiFi here for remote access and control
}

void loop() {
  // Code for facial recognition and controlling the servo

  // Capture and recognize the face
  camera_fb_t *fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Camera capture failed");
    return;
  }

  // Simulate face recognition logic (replace with actual logic)
  bool recognized = simulateFaceRecognition();

  if (recognized) {
    Serial.println("Face recognized, unlocking the door.");
    unlockDoor();
  }

  esp_camera_fb_return(fb);
  delay(1000); // Add some delay between recognition attempts
}

// Function to simulate face recognition (replace with actual algorithm)
bool simulateFaceRecognition() {
  // In a real application, you'd use an actual recognition algorithm
  // For demonstration, we just simulate a random success every few seconds
  return (millis() % 5000) < 1000; // Simulate success every 5 seconds
}

// Function to unlock the door (using servo motor)
void unlockDoor() {
  myServo.write(90); // Open the lock (90 degrees)
  delay(5000);       // Keep the lock open for 5 seconds
  myServo.write(0);  // Lock the door again
}

