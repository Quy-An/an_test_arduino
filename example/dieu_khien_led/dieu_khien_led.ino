void setup() {
  pinMode(10, OUTPUT); // Thiết lập chân 13 làm đầu ra (LED tích hợp)
  Serial.begin(9600);  // Bắt đầu giao tiếp serial
  
  noInterrupts(); // Tắt ngắt toàn bộ
  
  // Cấu hình Timer1
  TCCR1A = 0;               // Thiết lập toàn bộ TCCR1A register về 0
  TCCR1B = 0;               // Thiết lập toàn bộ TCCR1B register về 0
  TCNT1  = 0;               // Thiết lập bộ đếm Timer1 về 0
  
  // Thiết lập compare match register cho 1Hz tần số (16*10^6) / (1024*15625) - 1 (must be <65536)
  OCR1A = 15624;            
  // Turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Thiết lập CS10 và CS12 bits để chọn prescaler 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // Enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  
  interrupts(); // Cho phép ngắt toàn bộ
}

ISR(TIMER1_COMPA_vect) {    // Hàm xử lý ngắt Timer1
  digitalWrite(13, digitalRead(13) ^ 1); // Đổi trạng thái chân 13 mỗi khi ngắt xảy ra
  Serial.println("Ngắt Timer1 đã xảy ra");
}

void loop() {
  // Vòng lặp chính không làm gì trong trường hợp này
}
