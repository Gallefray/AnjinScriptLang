#include "QL.h"

// Input
keyObj keyInput;
mouseObj mouseInput;

void grabKeyInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    switch(action) // The case with the least amount of checks is done first :P
    {
	    case GLFW_PRESS:
	    	switch(key)
	    	{
	    		// Function keys start;
	    		case GLFW_KEY_F1:
	    			keyInput.F1 = true;
	    			break;
	    		case GLFW_KEY_F2:
	    			keyInput.F2 = true;
	    			break;
	    		case GLFW_KEY_F3:
	    			keyInput.F3 = true;
	    			break;
	    		case GLFW_KEY_F4:
	    			keyInput.F4 = true;
	    			break;
	    		case GLFW_KEY_F5:
	    			keyInput.F5 = true;
	    			break;
	    		case GLFW_KEY_F6:
	    			keyInput.F6 = true;
	    			break;
	    		case GLFW_KEY_F7:
	    			keyInput.F7 = true;
	    			break;
	    		case GLFW_KEY_F8:
	    			keyInput.F8 = true;
	    			break;
	    		case GLFW_KEY_F9:
	    			keyInput.F9 = true;
	    			break;
	    		case GLFW_KEY_F10:
	    			keyInput.F10 = true;
	    			break;
	    		case GLFW_KEY_F11:
	    			keyInput.F11 = true;
	    			break;
	    		case GLFW_KEY_F12:
	    			keyInput.F12 = true;
	    			break;
	    		// Function keys end;
	    		// Control Keys start;
	    		case GLFW_KEY_ESCAPE:
		 			keyInput.ESC = true;
			 		break;
	          	case GLFW_KEY_LEFT_SHIFT:
	          		keyInput.lSHIFT = true;
	          		break;
	          	case GLFW_KEY_RIGHT_SHIFT:
	          		keyInput.rSHIFT = true;
	          		break;
	          	case GLFW_KEY_LEFT_CONTROL:
	          		keyInput.lCTRL = true;
	          		break;
	          	case GLFW_KEY_RIGHT_CONTROL:
	          		keyInput.rCTRL = true;
	          		break;
	          	case GLFW_KEY_LEFT_SUPER:
	          		keyInput.lWIN = true;
	          		break;
	          	case GLFW_KEY_RIGHT_SUPER:
	          		keyInput.rWIN = true;
	          		break;
	          	case GLFW_KEY_LEFT_ALT:
	          		keyInput.lALT = true;
	          		break;
	          	case GLFW_KEY_RIGHT_ALT:
	          		keyInput.rALT = true;
	          		break;
	          	case GLFW_KEY_CAPS_LOCK:
	            	keyInput.CAPS = true;
	            	break;
	            case GLFW_KEY_NUM_LOCK:
	            	keyInput.NUM = true;
	            	break;
	          	// Control Keys end;
	          	// Number Keys start;
	          	case GLFW_KEY_0:
	          		keyInput.zero = true;
	          		break;
	          	case GLFW_KEY_1:
	          		keyInput.one = true;
	          		break;
	          	case GLFW_KEY_2:
	          		keyInput.two = true;
	          		break;
	          	case GLFW_KEY_3:
	          		keyInput.three = true;
	          		break;
	          	case GLFW_KEY_4:
	          		keyInput.four = true;
	          		break;
	          	case GLFW_KEY_5:
	          		keyInput.five = true;
	          		break;
	          	case GLFW_KEY_6:
	          		keyInput.six = true;
	          		break;
	          	case GLFW_KEY_7:
	          		keyInput.seven = true;
	          		break;
	          	case GLFW_KEY_8:
	          		keyInput.eight = true;
	          		break;
	          	case GLFW_KEY_9:
	          		keyInput.nine = true;
	          		break;
	          	// Number Keys end;
	          	// Letter Keys start;
	          	case GLFW_KEY_A:
	          		keyInput.a = true;
	          	 	break;
	          	case GLFW_KEY_B:
	          		keyInput.b = true;
	          		break;
	          	case GLFW_KEY_C:
	          		keyInput.c = true;
	          		break;
	          	case GLFW_KEY_D:
	          		keyInput.d = true;
	          		break;
	          	case GLFW_KEY_E:
	          		keyInput.e = true;
	          		break;
	          	case GLFW_KEY_F:
	          		keyInput.f = true;
	          		break;
	          	case GLFW_KEY_G:
	          		keyInput.g = true;
	          		break;
	          	case GLFW_KEY_H:
	          		keyInput.h = true;
	          		break;
	          	case GLFW_KEY_I:
	          		keyInput.i = true;
	          		break;
	          	case GLFW_KEY_J:
	          		keyInput.j = true;
	          		break;
	          	case GLFW_KEY_K:
	          		keyInput.k = true;
	          		break;
	          	case GLFW_KEY_L:
	          		keyInput.l = true;
	          		break;
	          	case GLFW_KEY_M:
	          		keyInput.m = true;
	          		break;
	          	case GLFW_KEY_N:
	          		keyInput.n = true;
	          		break;
	          	case GLFW_KEY_O:
	          		keyInput.o = true;
	          		break;
	          	case GLFW_KEY_P:
	          		keyInput.p = true;
	          		break;
	          	case GLFW_KEY_Q:
	          		keyInput.q = true;
	          		break;
	          	case GLFW_KEY_R:
	          		keyInput.r = true;
	          		break;
	          	case GLFW_KEY_S:
	          		keyInput.s = true;
	          		break;
	          	case GLFW_KEY_T:
	          		keyInput.t = true;
	          		break;
	          	case GLFW_KEY_U:
	          		keyInput.u = true;
	          		break;
	          	case GLFW_KEY_V:
	          		keyInput.v = true;
	          		break;
	          	case GLFW_KEY_W:
	          		keyInput.w = true;
	          		break;
	          	case GLFW_KEY_X:
	          		keyInput.x = true;
	          		break;
	          	case GLFW_KEY_Y:
	          		keyInput.y = true;
	          		break;
	          	case GLFW_KEY_Z:
	          		keyInput.z = true;
	          		break;
	          	// Letter Keys end;
	          	// Editing Keys start;
		      	case GLFW_KEY_TAB:
	          		keyInput.tab = true;
	          		break;
	          	case GLFW_KEY_INSERT:
	          		keyInput.insert = true;
	          		break;
	          	case GLFW_KEY_HOME:
	           		keyInput.home = true;
	           		break;
	           	case GLFW_KEY_DELETE:
	          		keyInput.del = true;
	          		break;
	           	case GLFW_KEY_END:
	           		keyInput.end = true;
	           		break;
	           	case GLFW_KEY_PAGE_UP:
	           		keyInput.pgUp = true;
	           		break;
	           	case GLFW_KEY_PAGE_DOWN:
	           		keyInput.pgDown = true;
	           		break;
	           	case GLFW_KEY_BACKSPACE:
	          		keyInput.backspace = true;
	          		break;
	          	case GLFW_KEY_SPACE:
	          		keyInput.spacebar = true;
	          		break;
	          	// Editing Keys end;
	          	// Keypad Number Keys start;
	          	case GLFW_KEY_KP_0:
	          		keyInput.NUMzero = true;
	          		break;
	          	case GLFW_KEY_KP_1:
	          		keyInput.NUMone = true;
	          		break;
	          	case GLFW_KEY_KP_2:
	          		keyInput.NUMtwo = true;
	          		break;
	          	case GLFW_KEY_KP_3:
	          		keyInput.NUMthree = true;
	          		break;
	          	case GLFW_KEY_KP_4:
	          		keyInput.NUMfour = true;
	          		break;
	          	case GLFW_KEY_KP_5:
	          		keyInput.NUMfive = true;
	          		break;
	          	case GLFW_KEY_KP_6:
	          		keyInput.NUMsix = true;
	          		break;
	          	case GLFW_KEY_KP_7:
	          		keyInput.NUMseven = true;
	          		break;
	          	case GLFW_KEY_KP_8:
	          		keyInput.NUMeight = true;
	          		break;
	          	case GLFW_KEY_KP_9:
	          		keyInput.NUMnine = true;
	          		break;
	          	// Keypad Number Keys end;
	          	// Arrow Keys start;
	           	case GLFW_KEY_LEFT:
	          		keyInput.left = true;
	          		break;
	        	case GLFW_KEY_RIGHT:
	          		keyInput.right = true;
	          		break;
	        	case GLFW_KEY_UP:
	          		keyInput.up = true;
	          		break;
	        	case GLFW_KEY_DOWN:
	          		keyInput.down = true;
	          		break;
	          	// Arrow Keys end;
	        	default:
	          		break;
	    	}
	    	break;

	    case GLFW_RELEASE:
	    	//printf("1 - 1");
	    	switch(key)
	    	{
	    		//printf("1 - 2");
	    		// Function keys start;
	    		case GLFW_KEY_F1:
	    			keyInput.F1 = false;
	    			break;
	    		case GLFW_KEY_F2:
	    			keyInput.F2 = false;
	    			break;
	    		case GLFW_KEY_F3:
	    			keyInput.F3 = false;
	    			break;
	    		case GLFW_KEY_F4:
	    			keyInput.F4 = false;
	    			break;
	    		case GLFW_KEY_F5:
	    			keyInput.F5 = false;
	    			break;
	    		case GLFW_KEY_F6:
	    			keyInput.F6 = false;
	    			break;
	    		case GLFW_KEY_F7:
	    			keyInput.F7 = false;
	    			break;
	    		case GLFW_KEY_F8:
	    			keyInput.F8 = false;
	    			break;
	    		case GLFW_KEY_F9:
	    			keyInput.F9 = false;
	    			break;
	    		case GLFW_KEY_F10:
	    			keyInput.F10 = false;
	    			break;
	    		case GLFW_KEY_F11:
	    			keyInput.F11 = false;
	    			break;
	    		case GLFW_KEY_F12:
	    			keyInput.F12 = false;
	    			break;
	    		// Function keys end;
	    		// Control Keys start;
	    		case GLFW_KEY_ESCAPE:
		 			keyInput.ESC = false;
			 		break;
	          	case GLFW_KEY_LEFT_SHIFT:
	          		keyInput.lSHIFT = false;
	          		break;
	          	case GLFW_KEY_RIGHT_SHIFT:
	          		keyInput.rSHIFT = false;
	          		break;
	          	case GLFW_KEY_LEFT_CONTROL:
	          		keyInput.lCTRL = false;
	          		break;
	          	case GLFW_KEY_RIGHT_CONTROL:
	          		keyInput.rCTRL = false;
	          		break;
	          	case GLFW_KEY_LEFT_SUPER:
	          		keyInput.lWIN = false;
	          		break;
	          	case GLFW_KEY_RIGHT_SUPER:
	          		keyInput.rWIN = false;
	          		break;
	          	case GLFW_KEY_LEFT_ALT:
	          		keyInput.lALT = false;
	          		break;
	          	case GLFW_KEY_RIGHT_ALT:
	          		keyInput.rALT = false;
	          		break;
	          	case GLFW_KEY_CAPS_LOCK:
	            	keyInput.CAPS = false;
	            	break;
	            case GLFW_KEY_NUM_LOCK:
	            	keyInput.NUM = false;
	            	break;
	          	// Control Keys end;
	          	// Number Keys start;
	          	case GLFW_KEY_0:
	          		keyInput.zero = false;
	          		break;
	          	case GLFW_KEY_1:
	          		keyInput.one = false;
	          		break;
	          	case GLFW_KEY_2:
	          		keyInput.two = false;
	          		break;
	          	case GLFW_KEY_3:
	          		keyInput.three = false;
	          		break;
	          	case GLFW_KEY_4:
	          		keyInput.four = false;
	          		break;
	          	case GLFW_KEY_5:
	          		keyInput.five = false;
	          		break;
	          	case GLFW_KEY_6:
	          		keyInput.six = false;
	          		break;
	          	case GLFW_KEY_7:
	          		keyInput.seven = false;
	          		break;
	          	case GLFW_KEY_8:
	          		keyInput.eight = false;
	          		break;
	          	case GLFW_KEY_9:
	          		keyInput.nine = false;
	          		break;
	          	// Number Keys end;
	          	// Letter Keys start;
	          	case GLFW_KEY_A:
	          		keyInput.a = false;
	          	 	break;
	          	case GLFW_KEY_B:
	          		keyInput.b = false;
	          		break;
	          	case GLFW_KEY_C:
	          		keyInput.c = false;
	          		break;
	          	case GLFW_KEY_D:
	          		keyInput.d = false;
	          		break;
	          	case GLFW_KEY_E:
	          		keyInput.e = false;
	          		break;
	          	case GLFW_KEY_F:
	          		keyInput.f = false;
	          		break;
	          	case GLFW_KEY_G:
	          		keyInput.g = false;
	          		break;
	          	case GLFW_KEY_H:
	          		keyInput.h = false;
	          		break;
	          	case GLFW_KEY_I:
	          		keyInput.i = false;
	          		break;
	          	case GLFW_KEY_J:
	          		keyInput.j = false;
	          		break;
	          	case GLFW_KEY_K:
	          		keyInput.k = false;
	          		break;
	          	case GLFW_KEY_L:
	          		keyInput.l = false;
	          		break;
	          	case GLFW_KEY_M:
	          		keyInput.m = false;
	          		break;
	          	case GLFW_KEY_N:
	          		keyInput.n = false;
	          		break;
	          	case GLFW_KEY_O:
	          		keyInput.o = false;
	          		break;
	          	case GLFW_KEY_P:
	          		keyInput.p = false;
	          		break;
	          	case GLFW_KEY_Q:
	          		keyInput.q = false;
	          		break;
	          	case GLFW_KEY_R:
	          		keyInput.r = false;
	          		break;
	          	case GLFW_KEY_S:
	          		keyInput.s = false;
	          		break;
	          	case GLFW_KEY_T:
	          		keyInput.t = false;
	          		break;
	          	case GLFW_KEY_U:
	          		keyInput.u = false;
	          		break;
	          	case GLFW_KEY_V:
	          		keyInput.v = false;
	          		break;
	          	case GLFW_KEY_W:
	          		keyInput.w = false;
	          		break;
	          	case GLFW_KEY_X:
	          		keyInput.x = false;
	          		break;
	          	case GLFW_KEY_Y:
	          		keyInput.y = false;
	          		break;
	          	case GLFW_KEY_Z:
	          		keyInput.z = false;
	          		break;
	          	// Letter Keys end;
	          	// Editing Keys start;
		      	case GLFW_KEY_TAB:
	          		keyInput.tab = false;
	          		break;
	          	case GLFW_KEY_INSERT:
	          		keyInput.insert = false;
	          		break;
	          	case GLFW_KEY_HOME:
	           		keyInput.home = false;
	           		break;
	           	case GLFW_KEY_DELETE:
	          		keyInput.del = false;
	          		break;
	           	case GLFW_KEY_END:
	           		keyInput.end = false;
	           		break;
	           	case GLFW_KEY_PAGE_UP:
	           		keyInput.pgUp = false;
	           		break;
	           	case GLFW_KEY_PAGE_DOWN:
	           		keyInput.pgDown = false;
	           		break;
	           	case GLFW_KEY_BACKSPACE:
	          		keyInput.backspace = false;
	          		break;
	          	case GLFW_KEY_SPACE:
	          		keyInput.spacebar = false;
	          		break;
	          	// Editing Keys end;
	          	// Keypad Number Keys start;
	          	case GLFW_KEY_KP_0:
	          		keyInput.NUMzero = false;
	          		break;
	          	case GLFW_KEY_KP_1:
	          		keyInput.NUMone = false;
	          		break;
	          	case GLFW_KEY_KP_2:
	          		keyInput.NUMtwo = false;
	          		break;
	          	case GLFW_KEY_KP_3:
	          		keyInput.NUMthree = false;
	          		break;
	          	case GLFW_KEY_KP_4:
	          		keyInput.NUMfour = false;
	          		break;
	          	case GLFW_KEY_KP_5:
	          		keyInput.NUMfive = false;
	          		break;
	          	case GLFW_KEY_KP_6:
	          		keyInput.NUMsix = false;
	          		break;
	          	case GLFW_KEY_KP_7:
	          		keyInput.NUMseven = false;
	          		break;
	          	case GLFW_KEY_KP_8:
	          		keyInput.NUMeight = false;
	          		break;
	          	case GLFW_KEY_KP_9:
	          		keyInput.NUMnine = false;
	          		break;
	          	// Keypad Number Keys end;
	          	// Arrow Keys start;
	           	case GLFW_KEY_LEFT:
	          		keyInput.left = false;
	          		break;
	        	case GLFW_KEY_RIGHT:
	          		keyInput.right = false;
	          		break;
	        	case GLFW_KEY_UP:
	          		keyInput.up = false;
	          		break;
	        	case GLFW_KEY_DOWN:
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

// case SDL_MOUSEMOTION:
	  		// mouseInput.x = event.motion.x;
	  		// mouseInput.y = event.motion.y;
	  		// break;

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