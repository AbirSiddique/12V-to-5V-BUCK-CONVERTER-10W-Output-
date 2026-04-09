// ===== USER VARIABLE =====
float dutyCycle = 70.0;   // Duty cycle in % (0.0 – 100.0)

void setup() {
  pinMode(9, OUTPUT);   // OC1A output

  // Stop Timer1
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  // Set TOP value for 40 kHz
  ICR1 = 399;

  // -------- SET DUTY CYCLE ----------
  OCR1A = (uint16_t)((dutyCycle / 100.0) * (ICR1 + 1));

  // Fast PWM, TOP = ICR1
  TCCR1A |= (1 << COM1A1);   // Non-inverting mode
  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12) | (1 << WGM13);

  // No prescaler (16 MHz)
  TCCR1B |= (1 << CS10);
}

void loop() {
  // Nothing needed here
}