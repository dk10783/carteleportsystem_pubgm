if (Vehicle.find("invalid") == std::string::npos)
						{
							Vector3 screen;
							int distance;
							if (Settings::carteleport)
							{
								Offsets::currIndexcar = ScreenInfo::carbesttarget();
							}
							vhi.Address = Offsets::entityAddv;
							vhi.displayName = Vehicle;
							vhi.VehicleComm = Memory::iGet(Offsets::entityAddv + 0x6dc);
							Offsets::vehicledata.push_back(vhi);
						}
