/*
 =======================================================================================================================

	T8 Units Script
	
	Funktion:	fn_broadcastHint.sqf
	Author:		T-800a
	E-Mail:		t-800a@gmx.net

 =======================================================================================================================
*/

#include <..\MACRO.hpp>

private _text = param [ 0, "", [""]];

_text = parseText format [ "<t size='1.5' color='#FE9A2E' align='right'>[ T8 Units ]</t><br /><t size='1' color='#FE9A2E' align='left'>%1</t>", _text ];
_text remoteExec [ "hint", -2 ]; 


// [ _text ] remoteExec [ "T8U_fnc_Hint", 0, false ];
// [[ _text ], "T8U_fnc_Hint" ] spawn BIS_fnc_MP;
