local heavyWeapons = {
    Glaives = "HeavyWeapon2014",
    Greataxes = "HeavyWeapon2014",
    Greatswords = "HeavyWeapon2014",
    Halberds = "HeavyWeapon2014",
    Mauls = "HeavyWeapon2014",
    Pikes = "HeavyWeapon2014",
    HeavyCrossbows = "HeavyWeapon2014",
    Longbows = "HeavyWeapon2014"
}

local function hasHeavyProperty(weaponProperty)
    if weaponProperty == nil then
        return false
    end
    for _, property in ipairs(weaponProperty) do
        if property == "Heavy" then
            return true
        end
    end
    return false
end

local function weaponPassiveAssign(weaponType)
	for _, proficiencyGroup in ipairs(weaponType) do
		local newPassive = heavyWeapons[proficiencyGroup]
		
		if newPassive then
			return newPassive
		end
	end
	
	return nil
end

local function addHeavyWeaponPassive()
    for _, name in ipairs(Ext.Stats.GetStats("Weapon")) do
        local weapon = Ext.Stats.Get(name)

		if weapon then
			local weaponType = weapon["Proficiency Group"]
			local weaponProperty = weapon["Weapon Properties"]

			local newPassive = weaponPassiveAssign(weaponType)
			local isHeavy = hasHeavyProperty(weaponProperty)
			
			if newPassive and isHeavy then
                weapon.PassivesOnEquip = (weapon.PassivesOnEquip and (weapon.PassivesOnEquip .. ";") or "") .. newPassive
                Ext.Stats.Sync(name)
            end
        end
    end
end

Ext.Events.StatsLoaded:Subscribe(addHeavyWeaponPassive)