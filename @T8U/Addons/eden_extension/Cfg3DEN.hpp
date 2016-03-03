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
							text = "- SELECT A TASK -";
							data = "ERROR";
							default = 1;
						};
						
						class item01
						{
							text		= "PATROL";
							data		= "PATROL";
							tooltip		= "";
						};
						
						class item02
						{
							text		= "PATROL AROUND";
							data		= "PATROL_AROUND";
							tooltip		= "";
						};
						
						class item03
						{
							text		= "PATROL GARRISON";
							data		= "PATROL_GARRISON";
							tooltip		= "";
						};
						
						class item04
						{
							text		= "PATROL MARKER";
							data		= "PATROL_MARKER";
							tooltip		= "";
						};
						
						class item05
						{
							text		= "PATROL URBAN";
							data		= "PATROL_URBAN";
							tooltip		= "";
						};
						
						class item06
						{
							text		= "GARRISON";
							data		= "GARRISON";
							tooltip		= "";
						};
						
						class item07
						{
							text		= "OCCUPY";
							data		= "OCCUPY";
							tooltip		= "";
						};
						
						class item08
						{
							text		= "DEFEND";
							data		= "DEFEND";
							tooltip		= "";
						};
						
						class item09
						{
							text		= "DEFEND_BASE";
							data		= "DEFEND_BASE";
							tooltip		= "";
						};
						
						class item10
						{
							text		= "OVERWATCH";
							data		= "OVERWATCH";
							tooltip		= "";
						};
						
						class item11
						{
							text		= "ATTACK";
							data		= "ATTACK";
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
						tooltip			= "The marker(s) where the group should do the selected task. Seperate multiple markers with a comma."; 
						property		= "T8U_introduce_markerArray"; 
						control			= "EditArray";
						expression		= "_this setVariable [ 'T8U_introduce_markerArray', _value ];";
						defaultValue	= "[ ""marker01"", ""marker02"", ""marker03"" ]";
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
					
					class EXECfunction
					{
						displayName		= "EXEC Function (optional)"; 
						tooltip			= "Is this is enabled the defined custom function will be executed after the group is introduced to the T8 Units script (same as the function which is executed on spawn)."; 
						property		= "T8U_introduce_EXECfunction"; 
						control			= "Checkbox";
						expression		= "_this setVariable [ 'T8U_introduce_EXECfunction', _value ];";
						defaultValue	= "false";
					};
					
					class customFunction
					{
						displayName		= "Function (optional)"; 
						tooltip			= "Custom function to execute after inroduction to T8 Units."; 
						property		= "T8U_introduce_function"; 
						control			= "Edit";
						expression		= "_this setVariable [ 'T8U_introduce_function', _value ];";
						defaultValue	= "MY_fnc_customFunction";
						
				// Optional properties
						unique			= 0;
						validate		= "none";
						typeName		= "STRING";
					};
					
					class patrolAroundDistance
					{
						displayName		= "Patrol Around Distance (optional)"; 
						tooltip			= "ONLY for PATROL_AROUND! Zone radius + patrol around distance (e.g. 50 m) is the distance where units will patrol around zones."; 
						property		= "T8U_introduce_patrolAroundDis"; 
						control			= "EditShort";
						expression		= "_this setVariable [ 'T8U_introduce_patrolAroundDis', _value ];";
						defaultValue	= 50;
						
				// Optional properties
						unique			= 0;
						validate		= "none";
						typeName		= "NUMBER";
					};

					class patrolMarkerSAD
					{
						displayName		= "Patrol Marker SaD Waypoints (optional)"; 
						tooltip			= "ONLY for PATROL_MARKER! The group will perfrom a SaD Waypoint on eacht patrol marker."; 
						property		= "T8U_introduce_patrolMarkerSAD"; 
						control			= "Checkbox";
						expression		= "_this setVariable [ 'T8U_introduce_patrolMarkerSAD', _value ];";
						defaultValue	= "false";
					};
					
					class occupyImmobile
					{
						displayName		= "Occcupy Immobile (optional)"; 
						tooltip			= "ONLY for OCCUPY! The group is immobile on their building positions."; 
						property		= "T8U_introduce_occupyImmobile"; 
						control			= "Checkbox";
						expression		= "_this setVariable [ 'T8U_introduce_occupyImmobile', _value ];";
						defaultValue	= "false";
					};
					
					class overwatchMinDis
					{
						displayName		= "Overwatch Minimum Distance (optional)"; 
						tooltip			= "ONLY for OVERWATCH! The minimum distance from the overatch marker to search for overwatch positions."; 
						property		= "T8U_introduce_overwatchMinDis"; 
						control			= "EditShort";
						expression		= "_this setVariable [ 'T8U_introduce_overwatchMinDis', _value ];";
						defaultValue	= 250;
						
				// Optional properties
						unique			= 0;
						validate		= "none";
						typeName		= "NUMBER";
					};
					
					class overwatchRange
					{
						displayName		= "Overwatch Range (optional)"; 
						tooltip			= "ONLY for OVERWATCH! The width of the ring, in which to search for Overwatch positions."; 
						property		= "T8U_introduce_overwatchRange"; 
						control			= "EditShort";
						expression		= "_this setVariable [ 'T8U_introduce_overwatchRange', _value ];";
						defaultValue	= 200;
						
				// Optional properties
						unique			= 0;
						validate		= "none";
						typeName		= "NUMBER";
					};
				};
			};
		};
	};
};
