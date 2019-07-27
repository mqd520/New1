#pragma once

namespace pck
{
	// packet cmd
	enum class EPacketCmd : int
	{

		// Common	---------------------------------------------------------------
		KeepAlive = 1,						// Keepalive 
		LoginSrvRequest = 8,				// Login server request
		LoginSrvResult = 9,					// Login server result
		// Common	---------------------------------------------------------------



		// Center srv	---------------------------------------------------------------
		ServerListen = 504,					// Server listen
		ServerListenEx = 2076,				// Server extend listen
		// Center srv	---------------------------------------------------------------



		// Game	---------------------------------------------------------------
		StartTable = 513,					// Start table
		StartTableResult = 517,				// Start table result
		// Game	---------------------------------------------------------------


		None
	};
}