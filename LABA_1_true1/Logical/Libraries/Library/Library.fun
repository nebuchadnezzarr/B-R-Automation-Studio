
{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FB_Integrator (*integrator*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : {REDUND_UNREPLICABLE} REAL; (*vhod*)
	END_VAR
	VAR_OUTPUT
		out : {REDUND_UNREPLICABLE} REAL; (*vihod*)
	END_VAR
	VAR
		dt : {REDUND_UNREPLICABLE} REAL; (*шаг расчета*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FB_Motor (*motor*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		u : {REDUND_UNREPLICABLE} REAL; (*входное напр€жение*)
	END_VAR
	VAR_OUTPUT
		w : {REDUND_UNREPLICABLE} REAL; (*частота вращени€*)
		phi : {REDUND_UNREPLICABLE} REAL; (*положение*)
	END_VAR
	VAR
		integrator : {REDUND_UNREPLICABLE} FB_Integrator; (*интегратор*)
		Tm : {REDUND_UNREPLICABLE} REAL; (*Ёл-мех посто€нна€*)
		Ke : {REDUND_UNREPLICABLE} REAL; (*посто€нна€ Ёƒ—*)
		dt : {REDUND_UNREPLICABLE} REAL; (*шаг расчета*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FB_Regulator (*regulator*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		e : {REDUND_UNREPLICABLE} REAL; (*рассогласование между задающим воздействием и реальной скоростью вращени€*)
	END_VAR
	VAR_OUTPUT
		u : {REDUND_UNREPLICABLE} REAL; (*напр€жение подаваемое на вход ƒѕ“*)
	END_VAR
	VAR
		k_p : {REDUND_UNREPLICABLE} REAL; (*пропорц*)
		k_i : {REDUND_UNREPLICABLE} REAL; (*интеграл*)
		integrator : {REDUND_UNREPLICABLE} FB_Integrator; (*интегратор*)
		iyOld : {REDUND_UNREPLICABLE} REAL; (*хранение предыдущего значени€*)
		max_abs_value : {REDUND_UNREPLICABLE} REAL; (*граница блока ограничени€*)
		dt : {REDUND_UNREPLICABLE} REAL; (*шаг расчета*)
		e_kp : {REDUND_UNREPLICABLE} REAL; (* промежуточное значение вычислений*)
	END_VAR
END_FUNCTION_BLOCK
