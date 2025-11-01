Ext.Require("BootstrapClient.lua")

Ext.Osiris.RegisterListener("SavegameLoaded", 0, "after", function()
    local partyMemberCharacters = Osi.DB_Players:Get(nil)
    for _, partyMember in ipairs(partyMemberCharacters) do
        UpdateDeityTags(partyMember[1])
    end
end)

Ext.Osiris.RegisterListener("TagSet", 2, "after", function(character)
    if (#Osi.DB_Players:Get(character) > 0) then
        UpdateDeityTags(character)
    end
end)

function UpdateDeityTags(character)
    for _, row in ipairs(Osi.DB_GodClassAlignTags:Get(nil, nil, nil, nil)) do
        if (Osi.IsTagged(character, row[1]) == 1) then
            if (Osi.IsTagged(character, row[2]) == 0) then
                local alignment = Osi.DB_AlignClassTags:Get(row[4], nil, nil)[1][2]
                Osi.SetTag(character, row[2])
                Osi.SetTag(character, alignment)

                _P("Tagging " .. character .. " with " .. row[2] .. " and " .. alignment)
            end
        else
            if (Osi.IsTagged(character, row[2]) == 1) then
                local alignment = Osi.DB_AlignClassTags:Get(row[4], nil, nil)[1][2]
                Osi.ClearTag(character, row[2])
                Osi.ClearTag(character, alignment)

                _P("Detagging " .. character .. " with " .. row[2] .. " and " .. alignment)
            end
        end
    end
end
