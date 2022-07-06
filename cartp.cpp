void Esp::cartracker()
{
	bool cartracking = false;
	while (true)
	{
		if (Settings::carteleport) 
		{
			while (true)
			{
				DWORD carx;
				DWORD cary;
				DWORD carz;

				if (cartracking == false)
				{
					carx = Offsets::currIndexcar + 152;
					cary = Offsets::currIndexcar + 156;
					carz = Offsets::currIndexcar + 160;
					cartracking = true;
				}

				FLOAT carxX; // store car x axix
				FLOAT carxY; // store car y axix
				FLOAT carxZ; // store car z axix
				DWORD playerX = Memory::ReadMemoryEx<INT>(Offsets::uMyObject + 0x16c) + 0x150; // read player x axix
				DWORD playerY = Memory::ReadMemoryEx<INT>(Offsets::uMyObject + 0x16c) + 0x154; // read player y axix
				DWORD playerZ = Memory::ReadMemoryEx<INT>(Offsets::uMyObject + 0x16c) + 0x158; // read player z axix
				if (GetAsyncKeyState(VK_CAPITAL))// caps button to activate
				{
					ReadProcessMemory(Offsets::pHandle, (LPCVOID)carx, &carxX, sizeof(carxX), nullptr);
					ReadProcessMemory(Offsets::pHandle, (LPCVOID)cary, &carxY, sizeof(carxY), nullptr);
					ReadProcessMemory(Offsets::pHandle, (LPCVOID)carz, &carxZ, sizeof(carxZ), nullptr);
					Memory::WriteMemoryEx<FLOAT>(playerX, (carxX)); // write player x axix
					Memory::WriteMemoryEx<FLOAT>(playerY, (carxY)); // write player y axix
					Memory::WriteMemoryEx<FLOAT>(playerZ, (carxZ + 281)); // write player z axix
					std::cout << "CAR ADRESSS :  " << Offsets::currIndexcar << std::endl;
				}
				if (!GetAsyncKeyState(VK_CAPITAL)) // caps button to deactivate
				{
					cartracking = false;
					break;
				}
			}

		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
