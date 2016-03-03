/*
 =======================================================================================================================

	T8 Units: 3DEN Extension

	File:		Cfg3DEN.cpp
	Author:		T-800a
	E-Mail:		T-800a@gmx.net

 =======================================================================================================================
*/

#include "\a3\3DEN\UI\macros.inc"

// Base class templates
class ctrlCombo;

class Cfg3DEN 
{
	class Attributes
	{
		// Base class templates
		class Title;
		class Combo : Title
		{
			class Controls
			{
				class Title;
				class Value;
			};
			
		};

		class T8U_combo_task : Combo
		{
			
			class Controls : Controls
			{
				class Title : Title {};
				class Value : Value
				{
					
					class Items
					{
						class item00
						{
							text = "- select a task -";
							data = "ERROR";
							default = 1;
						};
						
						class item01
						{
							text		= "patrol";
							data		= "PATROL";
							tooltip		= "";
						};
						
						class item02
						{
							text		= "patrol around";
							data		= "PATROL_AROUND";
							tooltip		= "";
						};
					};
					
					class ItemsConfig {};
				};
			};
		};
	};
	
	
	class Group
	{
		class AttributeCategories
		{
			class T8Units
			{
				displayName		= "T8 Units";
				collapsed		= 1;
				
				class Attributes
				{
					class introduce
					{
						displayName		= "Enable"; 
						tooltip			= "Introduce the selected group to the T8 Units Script"; 
						property		= "T8U_introduce"; 
						control			= "Checkbox";
						expression		= "if ( !is3DEN AND !isNil 'T8U_fnc_introduce' ) then {[ _value, _this ] spawn { waitUntil { time > 5 }; if ( _this select 0 ) then {( _this select 1 ) spawn T8U_fnc_introduce; };};};";
						defaultValue	= "false";
					};
					
					class task
					{
						displayName		= "Task"; 
						tooltip			= "Selcet the task your group should execute."; 
						property		= "T8U_introduce_task";
						control			= "T8U_combo_task"; 
						expression		= "_this setVariable [ 'T8U_introduce_task', _value ];";
						defaultValue	= "ERROR";

				// Optional properties
						unique = 0;
						validate = "none";
						typeName = "STRING";
					};
					
					class markerArray
					{
						displayName		= "Marker"; 
						tooltip			= "The marker area(s) where the group should do the selected task in."; 
						property		= "T8U_introduce_markerArray"; 
						control			= "EditArray";
						expression		= "_this setVariable [ 'T8U_introduce_markerArray', _value ];";
						defaultValue	= "[ ""marker01"", ""marker02"", ""marker03"" ]";
					};
					
					class commShare
					{
						displayName		= "Communication: Share"; 
						tooltip			= "The group will share information about enemies with other groups."; 
						property		= "T8U_introduce_comm_share"; 
						control			= "Checkbox";
						expression		= "_this setVariable [ 'T8U_introduce_comm_share', _value ];";
						defaultValue	= "true";
					};
					
					class commCall
					{
						displayName		= "Communication: Call"; 
						tooltip			= "The group will call other T8U groups (xor DAC groups) for help if not in superiority."; 
						property		= "T8U_introduce_comm_call"; 
						control			= "Checkbox";
						expression		= "_this setVariable [ 'T8U_introduce_comm_call', _value ];";
						defaultValue	= "true";
					};
					
					class commReact
					{
						displayName		= "Communication: React"; 
						tooltip			= "The group is allowed to react to threats even when they are on a assist mission (e.g. hold position if attacked and not in superiority)."; 
						property		= "T8U_introduce_comm_react"; 
						control			= "Checkbox";
						expression		= "_this setVariable [ 'T8U_introduce_comm_react', _value ];";
						defaultValue	= "true";
					};
					
					class infGroup
					{
						displayName		= "Infantry Group"; 
						tooltip			= "Is this groub a infantry group, or has it a fighting vehicle that should not be left behind."; 
						property		= "T8U_introduce_infGroup"; 
						control			= "Checkbox";
						expression		= "_this setVariable [ 'T8U_introduce_infGroup', _value ];";
						defaultValue	= "true";
					};
					
					class customFunction
					{
						displayName		= "Custom Function"; 
						tooltip			= "Custom function to execute after inroduction to T8 Units (same as the function which is executed on spawn)."; 
						property		= "T8U_introduce_function"; 
						control			= "Edit";
						expression		= "_this setVariable [ 'T8U_introduce_function', _value ];";
						defaultValue	= "MY_fnc_customFunction";
						
				// Optional properties
						unique			= 0;
						validate		= "none";
						typeName		= "STRING";
					};
				};
			};
		};
	};
};
