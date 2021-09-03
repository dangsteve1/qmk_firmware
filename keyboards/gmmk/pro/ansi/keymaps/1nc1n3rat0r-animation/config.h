/* 
Config to suspend RGB when computer is off or sleeping
See: https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#suspended-state-id-suspended-state
*/
#define RGB_DISABLE_WHEN_USB_SUSPENDED true

/*
Re-defining encoder resolution for replacement rotary encoder:
Alps Alpine EC11N1524402

Remove the ENCODER_RESOLUTION define if you are using the default GMMK Pro rotary encoder
*/ 
#define ENCODER_RESOLUTION 2



/*
	Enable RGB Matrix Effects
	https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#rgb-matrix-effects-id-rgb-matrix-effects
*/
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT

/* 
	To Enable RGB reactive effects
	First add:
	#define RGB_MATRIX_KEYPRESSES
	OR
	#define RGB_MATRIX_KEYRELEASES

	Then add which reactive effects you want to enable.
	#define ENABLE_RGB_MATRIX_SOLID_REACTIVE

	If you do not include the first line, the animation will not be available.

*/


/*
	Additional startup config values
	https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#additional-config-h-options-id-additional-configh-options
*/ 
