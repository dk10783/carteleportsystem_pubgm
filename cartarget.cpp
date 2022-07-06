int ScreenInfo::carbesttarget() {
	float targetDistance = 9999.0;
	Vector2 retval;
	int dist, headdist = 0;
	int ret{};
	for (int i = 0; i < Offsets::vehicledatar.size(); i++)
	{
		DWORD tmpAddv = Memory::iGet(Offsets::vehicledatar[i].Address + Offsets::rootComponent);
		Vector3 Screen;
		Vector3 Position = Utilities::Readvector3(Memory::iGet(Offsets::vehicledatar[i].Address + Offsets::rootComponent) + Offsets::posOffset);
		if (WorldToScreen(Position, Screen, &dist, Offsets::vt))
		{
			
		    float cross_dist = sqrt(pow(Screen.x - UsableW / 2, 2) + pow(Screen.y - UsableH / 2, 2));
		    if (cross_dist < targetDistance)
		    {
		    	ret = Offsets::vehicledatar[i].Address;
		    	targetDistance = cross_dist;
		    
		    }
			
		}
	}
	return ret;
}
