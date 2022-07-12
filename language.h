#define GERMAN

#ifdef GERMAN

#define  ERROR               "!! ERROR !!" 
#define  ERROR_COMMENT       "Der Wert liegt über dem Schwellenwertbereich"
#define  WARINING            "!! WARNUNG !!" 
#define  WARNING_COMMENT     "Der Wert erreicht den Schwellenwertbereich"
#define  PRESENT_VALUE       "Barwert ="
#define  TEMPERATURE         "Temperatur"
#define  SOC                 "Ladezustand"
#define  CHARGE_RATE         "Ladestrom"

#else
	
#define  ERROR               "!! ERROR !!" 
#define  ERROR_COMMENT       "value is more than the threshold range"
#define  WARINING            "!! WARINING !!" 
#define  WARNING_COMMENT     "value is reaching threshold range"
#define  PRESENT_VALUE       "Present value ="
#define  TEMPERATURE         "Temperature"
#define  SOC                 "State of Charge"
#define  CHARGE_RATE         "Charge Rate"

#endif
