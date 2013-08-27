#include "QL.h"

SDL_Event event;

// Input
keyObj keyInput;
mouseObj mouseInput;

void grabInput()
{
	SDL_PollEvent(&event);   //Poll our SDL key event for any keystrokes.
    switch(event.type) // The case with the least amount of checks is done first :P
    {
    	case SDL_MOUSEMOTION:
	  		mouseInput.x = event.motion.x;
	  		mouseInput.y = event.motion.y;
	  		break;

	  	// case SDL_MOUSEBUTTONDOWN:
	  	// 	switch(event.button.button)
	  	// 	{
	  	// 		case SDL_BUTTON_LEFT:
	  	// 			mouseInput.leftButton = true;
	  	// 			break;
				// case SDL_BUTTON_MIDDLE:
				// 	mouseInput.middleButton = true;
				// 	break;
	  	// 		case SDL_BUTTON_RIGHT:
		  // 			mouseInput.rightButton = true;
		  // 			break;
		  // 		default:
		  // 			break;
	  	// 	}

	  	// case SDL_MOUSEBUTTONUP:
	  	// 	switch(event.button.button)
	  	// 	{
	  	// 		case SDL_BUTTON_LEFT:
	  	// 			mouseInput.leftButton = false;
	  	// 			break;
				// case SDL_BUTTON_MIDDLE:
				// 	mouseInput.middleButton = false;
				// 	break;
	  	// 		case SDL_BUTTON_RIGHT:
		  // 			mouseInput.rightButton = false;
		  // 			break;
		  // 		default:
		  // 			break;
	  	// 	}

	    case SDL_KEYDOWN:
	    	switch(event.key.keysym.sym)
	    	{
	    		// Function keys start;
	    		case SDLK_F1:
	    			keyInput.F1 = true;
	    			break;
	    		case SDLK_F2:
	    			keyInput.F2 = true;
	    			break;
	    		case SDLK_F3:
	    			keyInput.F3 = true;
	    			break;
	    		case SDLK_F4:
	    			keyInput.F4 = true;
	    			break;
	    		case SDLK_F5:
	    			keyInput.F5 = true;
	    			break;
	    		case SDLK_F6:
	    			keyInput.F6 = true;
	    			break;
	    		case SDLK_F7:
	    			keyInput.F7 = true;
	    			break;
	    		case SDLK_F8:
	    			keyInput.F8 = true;
	    			break;
	    		case SDLK_F9:
	    			keyInput.F9 = true;
	    			break;
	    		case SDLK_F10:
	    			keyInput.F10 = true;
	    			break;
	    		case SDLK_F11:
	    			keyInput.F11 = true;
	    			break;
	    		case SDLK_F12:
	    			keyInput.F12 = true;
	    			break;
	    		// Function keys end;
	    		// Control Keys start;
	    		case SDLK_ESCAPE:
		 			keyInput.ESC = true;
			 		break;
	          	case SDLK_LSHIFT:
	          		keyInput.lSHIFT = true;
	          		break;
	          	case SDLK_RSHIFT:
	          		keyInput.rSHIFT = true;
	          		break;
	          	case SDLK_LCTRL:
	          		keyInput.lCTRL = true;
	          		break;
	          	case SDLK_RCTRL:
	          		keyInput.rCTRL = true;
	          		break;
	          	case SDLK_LSUPER:
	          		keyInput.lWIN = true;
	          		break;
	          	case SDLK_RSUPER:
	          		keyInput.rWIN = true;
	          		break;
	          	case SDLK_LALT:
	          		keyInput.lALT = true;
	          		break;
	          	case SDLK_RALT:
	          		keyInput.rALT = true;
	          		break;
	          	case SDLK_CAPSLOCK:
	            	keyInput.CAPS = true;
	            	break;
	            case SDLK_NUMLOCK:
	            	keyInput.NUM = true;
	            	break;
	          	// Control Keys end;
	          	// Number Keys start;
	          	case SDLK_0:
	          		keyInput.zero = true;
	          		break;
	          	case SDLK_1:
	          		keyInput.one = true;
	          		break;
	          	case SDLK_2:
	          		keyInput.two = true;
	          		break;
	          	case SDLK_3:
	          		keyInput.three = true;
	          		break;
	          	case SDLK_4:
	          		keyInput.four = true;
	          		break;
	          	case SDLK_5:
	          		keyInput.five = true;
	          		break;
	          	case SDLK_6:
	          		keyInput.six = true;
	          		break;
	          	case SDLK_7:
	          		keyInput.seven = true;
	          		break;
	          	case SDLK_8:
	          		keyInput.eight = true;
	          		break;
	          	case SDLK_9:
	          		keyInput.nine = true;
	          		break;
	          	// Number Keys end;
	          	// Letter Keys start;
	          	case SDLK_a:
	          		keyInput.a = true;
	          		break;
	          	case SDLK_b:
	          		keyInput.b = true;
	          		break;
	          	case SDLK_c:
	          		keyInput.c = true;
	          		break;
	          	case SDLK_d:
	          		keyInput.d = true;
	          		break;
	          	case SDLK_e:
	          		keyInput.e = true;
	          		break;
	          	case SDLK_f:
	          		keyInput.f = true;
	          		break;
	          	case SDLK_g:
	          		keyInput.g = true;
	          		break;
	          	case SDLK_h:
	          		keyInput.h = true;
	          		break;
	          	case SDLK_i:
	          		keyInput.i = true;
	          		break;
	          	case SDLK_j:
	          		keyInput.j = true;
	          		break;
	          	case SDLK_k:
	          		keyInput.k = true;
	          		break;
	          	case SDLK_l:
	          		keyInput.l = true;
	          		break;
	          	case SDLK_m:
	          		keyInput.m = true;
	          		break;
	          	case SDLK_n:
	          		keyInput.n = true;
	          		break;
	          	case SDLK_o:
	          		keyInput.o = true;
	          		break;
	          	case SDLK_p:
	          		keyInput.p = true;
	          		break;
	          	case SDLK_q:
	          		keyInput.q = true;
	          		break;
	          	case SDLK_r:
	          		keyInput.r = true;
	          		break;
	          	case SDLK_s:
	          		keyInput.s = true;
	          		break;
	          	case SDLK_t:
	          		keyInput.t = true;
	          		break;
	          	case SDLK_u:
	          		keyInput.u = true;
	          		break;
	          	case SDLK_v:
	          		keyInput.v = true;
	          		break;
	          	case SDLK_w:
	          		keyInput.w = true;
	          		break;
	          	case SDLK_x:
	          		keyInput.x = true;
	          		break;
	          	case SDLK_y:
	          		keyInput.y = true;
	          		break;
	          	case SDLK_z:
	          		keyInput.z = true;
	          		break;
	          	// Letter Keys end;
	          	// Editing Keys start;
		      	case SDLK_TAB:
	          		keyInput.tab = true;
	          		break;
	          	case SDLK_INSERT:
	          		keyInput.insert = true;
	          		break;
	          	case SDLK_HOME:
	           		keyInput.home = true;
	           		break;
	           	case SDLK_DELETE:
	          		keyInput.del = true;
	          		break;
	           	case SDLK_END:
	           		keyInput.end = true;
	           		break;
	           	case SDLK_PAGEUP:
	           		keyInput.pgUp = true;
	           		break;
	           	case SDLK_PAGEDOWN:
	           		keyInput.pgDown = true;
	           		break;
	           	case SDLK_BACKSPACE:
	          		keyInput.backspace = true;
	          		break;
	          	case SDLK_SPACE:
	          		keyInput.spacebar = true;
	          		break;
	          	// Editing Keys end;
	          	// Keypad Number Keys start;
	          	case SDLK_KP0:
	          		keyInput.NUMzero = true;
	          		break;
	          	case SDLK_KP1:
	          		keyInput.NUMone = true;
	          		break;
	          	case SDLK_KP2:
	          		keyInput.NUMtwo = true;
	          		break;
	          	case SDLK_KP3:
	          		keyInput.NUMthree = true;
	          		break;
	          	case SDLK_KP4:
	          		keyInput.NUMfour = true;
	          		break;
	          	case SDLK_KP5:
	          		keyInput.NUMfive = true;
	          		break;
	          	case SDLK_KP6:
	          		keyInput.NUMsix = true;
	          		break;
	          	case SDLK_KP7:
	          		keyInput.NUMseven = true;
	          		break;
	          	case SDLK_KP8:
	          		keyInput.NUMeight = true;
	          		break;
	          	case SDLK_KP9:
	          		keyInput.NUMnine = true;
	          		break;
	          	// Keypad Number Keys end;
	          	// Arrow Keys start;
	           	case SDLK_LEFT:
	          		keyInput.left = true;
	          		break;
	        	case SDLK_RIGHT:
	          		keyInput.right = true;
	          		break;
	        	case SDLK_UP:
	          		keyInput.up = true;
	          		break;
	        	case SDLK_DOWN:
	          		keyInput.down = true;
	          		break;
	          	// Arrow Keys end;
	        	default:
	          		break;
	    	}
	    	break;

	    case SDL_KEYUP:
	    	//printf("1 - 1");
	    	switch(event.key.keysym.sym)
	    	{
	    		//printf("1 - 2");
	    		// Function keys start;
	    		case SDLK_F1:
	    			keyInput.F1 = false;
	    			break;
	    		case SDLK_F2:
	    			keyInput.F2 = false;
	    			break;
	    		case SDLK_F3:
	    			keyInput.F3 = false;
	    			break;
	    		case SDLK_F4:
	    			keyInput.F4 = false;
	    			break;
	    		case SDLK_F5:
	    			keyInput.F5 = false;
	    			break;
	    		case SDLK_F6:
	    			keyInput.F6 = false;
	    			break;
	    		case SDLK_F7:
	    			keyInput.F7 = false;
	    			break;
	    		case SDLK_F8:
	    			keyInput.F8 = false;
	    			break;
	    		case SDLK_F9:
	    			keyInput.F9 = false;
	    			break;
	    		case SDLK_F10:
	    			keyInput.F10 = false;
	    			break;
	    		case SDLK_F11:
	    			keyInput.F11 = false;
	    			break;
	    		case SDLK_F12:
	    			keyInput.F12 = false;
	    			break;
	    		// Function keys end;
	    		// Control Keys start;
	    		case SDLK_ESCAPE:
	          		keyInput.ESC = true;
	          		break;
	          	case SDLK_LSHIFT:
	          		keyInput.lSHIFT = true;
	          		break;
	          	case SDLK_RSHIFT:
	          		keyInput.rSHIFT = true;
	          		break;
	          	case SDLK_LCTRL:
	          		keyInput.lCTRL = true;
	          		break;
	          	case SDLK_RCTRL:
	          		keyInput.rCTRL = true;
	          		break;
	          	case SDLK_LALT:
	          		keyInput.lALT = true;
	          		break;
	          	case SDLK_RALT:
	          		keyInput.rALT = true;
	          		break;
	          	case SDLK_CAPSLOCK:
	            	keyInput.CAPS = true;
	            	break;
	            case SDLK_NUMLOCK:
	            	keyInput.NUM = true;
	            	break;
	          	// Control Keys end;
	          	// Number Keys start;
	          	case SDLK_0:
	          		keyInput.zero = false;
	          		break;
	          	case SDLK_1:
	          		keyInput.one = false;
	          		break;
	          	case SDLK_2:
	          		keyInput.two = false;
	          		break;
	          	case SDLK_3:
	          		keyInput.three = false;
	          		break;
	          	case SDLK_4:
	          		keyInput.four = false;
	          		break;
	          	case SDLK_5:
	          		keyInput.five = false;
	          		break;
	          	case SDLK_6:
	          		keyInput.six = false;
	          		break;
	          	case SDLK_7:
	          		keyInput.seven = false;
	          		break;
	          	case SDLK_8:
	          		keyInput.eight = false;
	          		break;
	          	case SDLK_9:
	          		keyInput.nine = false;
	          		break;
	          	// Number Keys end;
	          	// Letter Keys start;
	          	case SDLK_a:
	          		keyInput.a = false;
	          		break;
	          	case SDLK_b:
	          		keyInput.b = false;
	          		break;
	          	case SDLK_c:
	          		keyInput.c = false;
	          		break;
	          	case SDLK_d:
	          		keyInput.d = false;
	          		break;
	          	case SDLK_e:
	          		keyInput.e = false;
	          		break;
	          	case SDLK_f:
	          		keyInput.f = false;
	          		break;
	          	case SDLK_g:
	          		keyInput.g = false;
	          		break;
	          	case SDLK_h:
	          		keyInput.h = false;
	          		break;
	          	case SDLK_i:
	          		keyInput.i = false;
	          		break;
	          	case SDLK_j:
	          		keyInput.j = false;
	          		break;
	          	case SDLK_k:
	          		keyInput.k = false;
	          		break;
	          	case SDLK_l:
	          		keyInput.l = false;
	          		break;
	          	case SDLK_m:
	          		keyInput.m = false;
	          		break;
	          	case SDLK_n:
	          		keyInput.n = false;
	          		break;
	          	case SDLK_o:
	          		keyInput.o = false;
	          		break;
	          	case SDLK_p:
	          		keyInput.p = false;
	          		break;
	          	case SDLK_q:
	          		keyInput.q = false;
	          		break;
	          	case SDLK_r:
	          		keyInput.r = false;
	          		break;
	          	case SDLK_s:
	          		keyInput.s = false;
	          		break;
	          	case SDLK_t:
	          		keyInput.t = false;
	          		break;
	          	case SDLK_u:
	          		keyInput.u = false;
	          		break;
	          	case SDLK_v:
	          		keyInput.v = false;
	          		break;
	          	case SDLK_w:
	          		keyInput.w = false;
	          		break;
	          	case SDLK_x:
	          		keyInput.x = false;
	          		break;
	          	case SDLK_y:
	          		keyInput.y = false;
	          		break;
	          	case SDLK_z:
	          		keyInput.z = false;
	          		break;
	          	// Letter Keys end;
	          	// Editing Keys start;
		      	case SDLK_TAB:
	          		keyInput.tab = false;
	          		break;
	          	case SDLK_INSERT:
	          		keyInput.insert = false;
	          		break;
	          	case SDLK_HOME:
	           		keyInput.home = false;
	           		break;
	           	case SDLK_DELETE:
	          		keyInput.del = false;
	          		break;
	           	case SDLK_END:
	           		keyInput.end = false;
	           		break;
	           	case SDLK_PAGEUP:
	           		keyInput.pgUp = false;
	           		break;
	           	case SDLK_PAGEDOWN:
	           		keyInput.pgDown = false;
	           		break;
	           	case SDLK_BACKSPACE:
	          		keyInput.backspace = false;
	          		break;
	          	case SDLK_SPACE:
	          		keyInput.spacebar = false;
	          		break;
	          	// Editing Keys end;
	          	// Keypad Number Keys start;
	          	case SDLK_KP0:
	          		keyInput.NUMzero = false;
	          		break;
	          	case SDLK_KP1:
	          		keyInput.NUMone = false;
	          		break;
	          	case SDLK_KP2:
	          		keyInput.NUMtwo = false;
	          		break;
	          	case SDLK_KP3:
	          		keyInput.NUMthree = false;
	          		break;
	          	case SDLK_KP4:
	          		keyInput.NUMfour = false;
	          		break;
	          	case SDLK_KP5:
	          		keyInput.NUMfive = false;
	          		break;
	          	case SDLK_KP6:
	          		keyInput.NUMsix = false;
	          		break;
	          	case SDLK_KP7:
	          		keyInput.NUMseven = false;
	          		break;
	          	case SDLK_KP8:
	          		keyInput.NUMeight = false;
	          		break;
	          	case SDLK_KP9:
	          		keyInput.NUMnine = false;
	          		break;
	          	// Keypad Number Keys end;
	          	// Arrow Keys start;
	           	case SDLK_LEFT:
	          		keyInput.left = false;
	          		break;
	        	case SDLK_RIGHT:
	          		keyInput.right = false;
	          		break;
	        	case SDLK_UP:
	          		keyInput.up = false;
	          		break;
	        	case SDLK_DOWN:
	          		keyInput.down = false;
	          		break;
	          	// Arrow Keys end;
		        default:
		          	break;
		    }
		    break;

		default:
			break;
  	}
}