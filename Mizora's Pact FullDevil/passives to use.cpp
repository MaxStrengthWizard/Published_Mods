















new entry "MizPact_LOW_Raphael_Reaper"
type "PassiveData"
// Soul Reaper
data "DisplayName" "h02eadcd1g2eadg4b6dgb68cg66989db440c6;2"
// When Raphael reduces an enemy's hit points to [1], he <LSTag Type="Status" Tooltip="LOW_RAPHAEL_SOULLESS">Severs</LSTag> the soul from their body. 
data "Description" "h59fed6acg4dd9g485fga0e6ge458b8b59542;3"
data "DescriptionParams" "0"
data "Icon" "statIcons_WildMagic_Memphit"
data "Properties" "Highlighted"
data "StatsFunctorContext" "OnDamage"
data "Conditions" "IsKillingBlow() and not HasStatus('LOW_RAPHAEL_SOULLESS') and Enemy() and not HasStatus('SG_Polymorph') and not Tagged('UNDEAD') and not Tagged('CONSTRUCT') and not Tagged('FIEND')"
data "StatsFunctors" "ApplyStatus(LOW_RAPHAEL_SOULLESS,100,-1);RestoreResource(SELF,SpellSlot,1,1);"




new entry "MizPact_Target_LOW_Raphael_RepelDivinity_Spell"
type "SpellData"
data "SpellType" "Target"
using "Target_HellishRebuke"
data "Level" "6"
data "SpellSchool" ""
data "TargetRadius" "30"
data "SpellRoll" "not SavingThrow(Ability.Dexterity,18)"
data "SpellSuccess" "ApplyStatus(LOW_RAPHAEL_STUNNED,100,4);"
data "SpellFail" ""
data "Icon" "Spell_HellishRebuke"
// Punish Divinity
data "DisplayName" "h4914d3e9g2f5bg4b1fgba1dg91acf04d7129;2"
// After taking Radiant damage, <LSTag Type="Status" Tooltip="LOW_RAPHAEL_STUNNED">Stun</LSTag> the attacker, allowing you to <LSTag Type="Spell" Tooltip="Target_LOW_Raphael_RepelDivinity_SoulDrain">Drain</LSTag> its hit points. 
data "Description" "h84346b6egdc1bg4f17g8353g0ce0d76e97a5;3"
data "DescriptionParams" ""
data "TooltipDamageList" ""
data "TooltipAttackSave" "Dexterity"
data "TooltipOnSave" ""
data "TooltipUpcastDescription" ""
data "TooltipUpcastDescriptionParams" ""
data "SpellAnimation" "3ff87abf-1ea1-4c32-aadf-c822d74c7dc0,,;,,;39daf365-ec06-49a8-81f3-9032640699d7,,;5c400e93-0266-499c-a2e1-75d53358460f,,;d8925ce4-d6d9-400c-92f5-ad772ef7f178,,;,,;eadedcce-d01b-4fbb-a1ae-d218f13aa5d6,,;,,;,,"
data "VerbalIntent" "Control"
data "SpellFlags" "IsSpell;HasSomaticComponent;HasVerbalComponent;IsHarmful;IsConcentration"
data "CastEffect" "08935a6f-9662-4d9c-bc40-53a390d8b990"
data "TargetEffect" "b67ce046-c85d-42c7-805d-51b82163b20b"
data "DamageType" ""

new entry "MizPact_LOW_RAPHAEL_REPELLING_DIVINITY"
type "StatusData"
data "StatusType" "BOOST"
using "LOW_HOUSEOFHOPE_AEGIS"
// Punish Divinity
data "DisplayName" "h3c296203geda0g45c5g81c7g5857570377b4;3"
// When hit with Radiant damage, Raphael can use a reaction to stun the attacker, leaving the impudent creature <LSTag Type="Status" Tooltip="LOW_RAPHAEL_STUNNED">Soul Wrenched</LSTag>.
data "Description" "ha4fdcdfegfb38g4aecg9c33g1f27f4047237;5"
data "StackId" "LOW_RAPHAEL_REPELLING_DIVINITY"
data "Passives" "LOW_Raphael_RepelDivinity"
data "RemoveConditions" ""
data "RemoveEvents" ""
data "TooltipPermanentWarnings" "91a03d92-ac55-4669-843b-c92fa360f99b"

new entry "MizPact_LOW_Raphael_RepelDivinity"
type "PassiveData"
using "Thought_Shield_Psychic_Reflection"
// Punish Divinity
data "DisplayName" "h6f76e0cdg42a0g413dg8359g078ad266347c;4"
// Raphael can <LSTag Type="Status" Tooltip="LOW_RAPHAEL_STUNNED">Stun</LSTag> a creature that hits him with Radiant damage, allowing him to <LSTag Type="Spell" Tooltip="Target_LOW_Raphael_RepelDivinity_SoulDrain">Drain</LSTag> its hit points. 
data "Description" "h13ce33c9ge111g47b5g84f5g89e4d43a7e40;10"
data "DescriptionParams" ""
data "Properties" "None"
data "Boosts" ""
data "StatsFunctorContext" "OnDamaged"
data "Conditions" "IsDamageTypeRadiant() and HasLastAttackTriggered()"
data "StatsFunctors" "IF(not IsConcentrating(context.Target) and not HasStatus('LOW_RAPHAEL_MONSTER_FORM',context.Target)):UseSpell(SWAP,Target_LOW_Raphael_RepelDivinity_Spell,true,true,true);IF(not IsConcentrating(context.Target) and HasStatus('LOW_RAPHAEL_MONSTER_FORM',context.Target)):UseSpell(SWAP,Target_LOW_Raphael_RepelDivinity_Spell_Ascended,true,true,true);IF(not IsConcentrating(context.Target)):RemoveStatus(LOW_RAPHAEL_REPELLING_DIVINITY)"









new entry "MizPact_Shout_LOW_Raphael_SoulSiphon"
type "SpellData"
data "SpellType" "Shout"
using "Shout_ActionSurge"
data "Cooldown" "OncePerTurn"
data "AIFlags" ""
data "SpellProperties" "AI_ONLY:ApplyStatus(SELF,AI_HELPER_BUFF_LARGE, 100, 1);AI_IGNORE:RestoreResource(SELF,SpellSlot,1,1);IF(not HasStatus('LOW_RAPHAEL_REPELLING_DIVINITY',context.Source)):ApplyStatus(SELF,LOW_RAPHAEL_REPELLING_DIVINITY, 100, -1);"
data "AreaRadius" "30"
data "TargetConditions" "Tagged('ACT3_LOW_HOUSEOFHOPE_SOULPILLAR') and not HasStatus('LOW_RAPHAEL_PILLAR_BLOCKED')"
// Consume Souls
data "DisplayName" "h1bea969dg18ccg48a5gb6f0g7a094bb9abf2;2"
// Absorb a soul from each Soul Pillar still standing to spend on powerful spells.<br><br>Your <LSTag Type="Status" Tooltip="LOW_RAPHAEL_REPELLING_DIVINITY">Punish Divinity</LSTag> is restored every time you absorb souls in this way. 
data "Description" "h5d04ec27g3ae0g4d70gabc2g2f2b1594b564;3"
data "TooltipStatusApply" ""
data "CastSound" "CrSpell_Cast_Raphael_SoulHarvest"
data "TargetSound" ""
data "UseCosts" "BonusActionPoint:1"
data "SpellAnimation" "9122eb08-93f1-4010-a275-f5ae3ec7c76e,,;,,;f6c50c60-5887-42fc-a64f-1841aee27af2,,;127df798-9826-4039-ad93-a363983ea0e9,,;5301d674-b7da-47b6-b4cf-2802ba33a9e9,,;,,;86b3cf93-21fb-4a3d-bed9-97d0a567d084,,;,,;,,"
data "SpellStyleGroup" ""
data "SpellFlags" "IgnoreSilence;RangeIgnoreBlindness;RangeIgnoreSourceBounds;RangeIgnoreTargetBounds;RangeIgnoreVerticalThreshold;IgnoreVisionBlock"
data "Requirements" ""
data "RequirementConditions" "not HasStatus('LOW_RAPHAEL_EASY') and not HasStatus('LOW_RAPHAEL_HARDCORE') and ((not HasStatus('LOW_RAPHAEL_SOUL_9') and not HasStatus('LOW_RAPHAEL_MONSTER_FORM')) or (not HasStatus('LOW_RAPHAEL_SOUL_9') and not HasStatus('LOW_RAPHAEL_SOUL_8') and not HasStatus('LOW_RAPHAEL_SOUL_7') and not HasStatus('LOW_RAPHAEL_SOUL_6') and not HasStatus('LOW_RAPHAEL_SOUL_5') and not HasStatus('LOW_RAPHAEL_SOUL_4') and HasStatus('LOW_RAPHAEL_MONSTER_FORM')))"
data "PrepareEffect" ""
data "CastEffect" "7ca21b0c-47e8-4378-b43e-bcfef5fec04c"
data "TargetEffect" "9e0ae869-e18b-4b55-9ec1-192a4ad252a9"


new entry "MizPact_LOW_RAPHAEL_SOUL_1"
type "StatusData"
data "StatusType" "BOOST"
// Soul Charges: 1
data "DisplayName" "h4107b35egdaf3g42adgb024gc5b6d85746d9;4"
// Raphael has 1 soul to spend on powerful spells.
data "Description" "h3230d8bdga9fdg4ae2g9ff0g53dfb16284ec;2"
data "Icon" "PassiveFeature_Portent_1"
data "StackId" "LOW_RAPHAEL_SOUL_1"
data "StackPriority" "5"
data "RemoveConditions" "not HasActionResource('SpellSlot', 1,1, false, false, context.Source) or HasActionResource('SpellSlot', 2,1, false, false, context.Source)"
data "RemoveEvents" "OnSpellCast;OnAttack;OnStatusApplied"
data "StatusPropertyFlags" "DisableCombatlog"
data "StatusEffect" "0314620c-99f2-4b0b-9f9e-a0b944afab13"

new entry "MizPact_LOW_RAPHAEL_SOUL_9"
type "StatusData"
data "StatusType" "BOOST"
using "LOW_RAPHAEL_SOUL_1"
// Souls Charges: 9
data "DisplayName" "hf8024f48g3db8g4491g9436gb23d3d13d94e;2"
// Raphael has 9 souls to spend on powerful spells.
data "Description" "h0375ddc5gc978g45aeg9340g14072418cd27;2"
data "Icon" "PassiveFeature_Portent_9"
data "StackId" "LOW_RAPHAEL_SOUL_9"
data "RemoveConditions" "not HasActionResource('SpellSlot', 9,1, false, false, context.Source)"


new entry "MizPact_Projectile_LOW_Raphael_LavaChains"
type "SpellData"
data "SpellType" "Projectile"
using "Projectile_ScorchingRay"
data "Level" "6"
data "SpellProperties" "GROUND:CreateSurface(1, 2,Hellfire);SurfaceChange(Ignite);GROUND:SurfaceChange(Melt)"
data "AmountOfTargets" "3"
data "SpellRoll" "not SavingThrow(Ability.Dexterity, SourceSpellDC()) "
data "SpellSuccess" "DealDamage(6d6,Fire,Magical);IF(not SavingThrow(Ability.Strength,SourceSpellDC())):Force(5)"
data "SpellFail" "DealDamage((6d6)/2,Fire,Magical);IF(not SavingThrow(Ability.Strength,SourceSpellDC())):Force(5)"
data "TargetConditions" "not Self() and not Dead() and Enemy()"
// Diabolic Chains
data "DisplayName" "h6d32ce11g65cag4ef8ga2b3g2b4d2ceace9d;4"
// Spend [2] souls you have consumed to lash out with [1] magmatic chains of <LSTag Type="Status" Tooltip="BURNING_HELLFIRE">Hellfire</LSTag> and push the targets back [3].
data "Description" "hc322babegf3e2g48cdgb218g96a9c301dbc8;8"
data "DescriptionParams" "3;2;Distance(5)"
data "TooltipDamageList" "DealDamage(6d6,Fire)"
data "TooltipAttackSave" "Dexterity"
data "TooltipUpcastDescription" ""
data "CastSound" "CrSpell_Cast_LavaChain"
data "UseCosts" "ActionPoint:1;SpellSlotsGroup:2:2:1"
data "SpellAnimation" "3ff87abf-1ea1-4c32-aadf-c822d74c7dc0,,;,,;b8240b32-2691-42d9-8889-90394682e6f5,,;17eea8c4-cf1e-4609-87c3-2179c3ebcca8,,;d8925ce4-d6d9-400c-92f5-ad772ef7f178,,;,,;eadedcce-d01b-4fbb-a1ae-d218f13aa5d6,,;,,;,,"
data "SpellAnimationIntentType" "Aggressive"
data "RechargeValues" ""
data "RequirementConditions" "HasStatus('LOW_RAPHAEL_MONSTER_FORM')"
data "PrepareEffect" ""
data "CastEffect" "b45e8bc8-c2ba-46df-91ee-ac63d9e256c5"
data "Sheathing" "DontChange"


new entry "MizPact_Zone_LOW_Raphael_LanguishingFire"
type "SpellData"
data "SpellType" "Zone"
using "Zone_BurningHands"
data "Level" "6"
data "SpellRoll" "not SavingThrow(Ability.Dexterity,15)"
data "SpellSuccess" "DealDamage(6d6, Fire,Magical)"
data "SpellFail" "DealDamage(6d6/2, Fire,Magical)"
data "TargetConditions" "not Dead() and not Ally() and not Item()"
// Flames of Avernus
data "DisplayName" "hb73f3e80ge609g4c3ag8cf6g87263cfeb97f;3"
// Loose a searing wave of infernal fire from your palms. 
data "Description" "h7bb3d42ag53c1g473bgaf3eg4df1239a951d;5"
data "DescriptionParams" "DealDamage(6d6, Fire)"
data "TooltipDamageList" "DealDamage(6d6, Fire)"
data "RequirementConditions" "not HasStatus('LOW_RAPHAEL_MONSTER_FORM') and not HasStatus('LOW_RAPHAEL_OVERCHARGE')"


new entry "MizPact_Projectile_LOW_Raphael_DancingFlame"
type "SpellData"
data "SpellType" "Projectile"
using "Projectile_FireBolt"
data "Level" "4"
data "SpellProperties" "GROUND:SurfaceChange(Ignite);GROUND:SurfaceChange(Melt);GROUND:IF(HasStatus('LOW_RAPHAEL_MONSTER_FORM',context.Source)):CreateSurface(1, 2,Hellfire);"
data "AmountOfTargets" "1"
data "SpellRoll" "not SavingThrow(Ability.Dexterity, SourceSpellDC()) "
data "SpellSuccess" "DealDamage(6d6,Fire,Magical);ApplyStatus(BURNING,100,2);"
data "SpellFail" "DealDamage((6d6)/2,Fire,Magical);"
data "TargetConditions" "not Self() and not Dead() and Enemy()"
// Igniting Spark
data "DisplayName" "hd60d072dg1f2fg45baga914g9fe2fc671a15;4"
// Launch a mote of infernal flame to set a target alight and <LSTag Type="Status" Tooltip="BURNING
data "Description" "hfc09dc2eg98f2g4c42gac43g2757292bc409;3"
data "DescriptionParams" "DealDamage(6d6, Fire)"
data "TooltipDamageList" "DealDamage(6d6,Fire)"
data "TooltipAttackSave" "Dexterity"


new entry "MizPact_Target_LOW_Raphael_FlameFury"
type "SpellData"
data "SpellType" "Target"
using "Target_FlameStrike"
data "Level" "6"
data "SpellProperties" "GROUND:SurfaceChange(Ignite);GROUND:SurfaceChange(Melt); GROUND:CreateSurface(3,2,Fire)"
data "RequirementConditions" "not HasStatus('LOW_RAPHAEL_MONSTER_FORM') and not HasStatus('LOW_RAPHAEL_OVERCHARGE')"
data "SpellRoll" "not SavingThrow(Ability.Dexterity,15)"
data "SpellSuccess" "DealDamage(8d8,Fire,Magical)"
data "SpellFail" "DealDamage(8d8/2,Fire,Magical)"
data "TargetConditions" "Enemy() and not Dead()"
// Incinerate
data "DisplayName" "h19304115ge85eg44d5g91d9gdbd3a9275958;2"
// Spend [1] soul to wreath a target in malevolent flame. 
data "Description" "h619a6c76gc33dg407eg83d4g9cf453fee817;3"
data "DescriptionParams" "DealDamage(8d8,Fire);"
data "ExtraDescription" ""
data "TooltipDamageList" "DealDamage(8d8,Fire,Magical)"
data "TooltipOnSave" ""
data "TooltipUpcastDescription" ""
data "TooltipUpcastDescriptionParams" ""
data "UseCosts" "ActionPoint:1;SpellSlotsGroup:2:2:1"
data "RechargeValues" "3-6"


new entry "MizPact_Target_LOW_Raphael_Heal"
type "SpellData"
data "SpellType" "Target"
using "Target_HealingWord"
data "Level" "6"
data "SpellSchool" ""
data "SpellProperties" "RegainHitPoints(3d6)"
data "TargetRadius" "18"
data "RequirementConditions" "not HasStatus('LOW_RAPHAEL_MONSTER_FORM') and not HasStatus('LOW_RAPHAEL_OVERCHARGE')"
data "TargetConditions" "Character() and not Dead() and Ally() and not Self() and Tagged('FIEND')"
// Infernal Salve
data "DisplayName" "hea6633c1gf685g4ea8g8ff4gf9005af41d32;3"
// Spend [2] soul to heal a Fiend. 
data "Description" "h7ffceeebg0da1g44fega583g21a8319d7fcc;2"
data "DescriptionParams" "RegainHitPoints(3d6);1"
data "TooltipDamageList" "RegainHitPoints(2d8)"
data "UseCosts" "BonusActionPoint:1;SpellSlotsGroup:1:1:1"
data "RechargeValues" "3-6"


new entry "MizPact_Target_LOW_Raphael_Summon_Eternal_Debtor_Consolidated"
type "SpellData"
data "SpellType" "Target"
using "Target_LOW_Raphael_Summon_Eternal_Debtor"
data "Level" "6"
data "SpellContainerID" ""
data "Cooldown" "OncePerTurn"
data "SpellProperties" "AI_IGNORE:GROUND:IF(HasStatus('LOW_RAPHAEL_ED1', context.Source)):Spawn(64e370e2-50b3-46a2-b689-962e03aac3e3,Projectile_AiHelper_Summon_Strong);AI_IGNORE:GROUND:IF(HasStatus('LOW_RAPHAEL_ED2', context.Source)):Spawn(9565ac2d-e1c2-4491-a875-9b22d1d07da6,Projectile_AiHelper_Summon_Strong);AI_IGNORE:GROUND:IF(HasStatus('LOW_RAPHAEL_ED3', context.Source)):Spawn(071f4891-c06f-4b69-b0ec-c15da2ae6c1d,Projectile_AiHelper_Summon_Strong);AI_IGNORE:GROUND:IF(HasStatus('LOW_RAPHAEL_ED4', context.Source)):Spawn(c7c1f545-ae6d-46dd-ae16-1068ccc62f88,Projectile_AiHelper_Summon_Strong);AI_IGNORE:GROUND:IF(HasStatus('LOW_RAPHAEL_ED5', context.Source)):Spawn(9b255f7f-5de6-4d46-8abb-3fc2a6851b01,Projectile_AiHelper_Summon_Strong);AI_IGNORE:GROUND:IF(HasStatus('LOW_RAPHAEL_ED6', context.Source)):Spawn(3e450d8a-4832-4b36-bf4d-8fcc8304ef46,Projectile_AiHelper_Summon_Strong);AI_IGNORE:GROUND:IF(HasStatus('LOW_RAPHAEL_ED6',context.Source)):ApplyStatus(SELF,LOW_RAPHAEL_ED7,100,1);AI_IGNORE:GROUND:IF(HasStatus('LOW_RAPHAEL_ED5',context.Source)):ApplyStatus(SELF,LOW_RAPHAEL_ED6,100,-1);AI_IGNORE:GROUND:IF(HasStatus('LOW_RAPHAEL_ED4',context.Source)):ApplyStatus(SELF,LOW_RAPHAEL_ED5,100,-1);AI_IGNORE:GROUND:IF(HasStatus('LOW_RAPHAEL_ED3',context.Source)):ApplyStatus(SELF,LOW_RAPHAEL_ED4,100,-1);AI_IGNORE:GROUND:IF(HasStatus('LOW_RAPHAEL_ED2',context.Source)):ApplyStatus(SELF,LOW_RAPHAEL_ED3,100,-1);AI_IGNORE:GROUND:IF(HasStatus('LOW_RAPHAEL_ED1',context.Source)):ApplyStatus(SELF,LOW_RAPHAEL_ED2,100,-1);AI_ONLY:GROUND:Spawn(64e370e2-50b3-46a2-b689-962e03aac3e3,Projectile_AiHelper_Summon_Strong);"
data "Requirements" ""
data "RequirementConditions" "not HasStatus('LOW_RAPHAEL_ED7') and not HasStatus('LOW_RAPHAEL_MONSTER_FORM') and not HasStatus('LOW_RAPHAEL_OVERCHARGE')"
data "TargetConditions" "CanStand('03f340c1-a26e-427e-968a-94c795015965') and not Character() and not Self()"
data "Icon" "Action_Warlock_PactOfTheChain_Quasit"
// Invocation of Eternal Debt
data "DisplayName" "h278ea8ecg7e7eg4cffg8c6ag5465e9d783ad;2"
// Spend [1] soul to summon an Eternal Debtor to your side. 
data "Description" "h7e7d1a3ag0296g4b82gbf80g5e7466575198;3"
data "DescriptionParams" "1"
data "CastSound" "CrSpell_Cast_Raphael_SummonEternalDebtors"
data "TargetSound" ""
data "UseCosts" "BonusActionPoint:1;SpellSlotsGroup:1:1:1"
data "RitualCosts" ""
data "SpellAnimation" "6f42f5f3-7a5a-4441-a02e-71b0450ac4b7,,;,,;822eeb8a-2e92-4f2d-aff4-023138130e68,,;1c9b09ae-9038-4341-be80-469691bc9f95,,;42aaefdc-cf9b-4249-b159-285041851f69,,;,,;20e11c98-fff9-4417-88de-5bcc2368a1bd,,;,,;,,"
data "SpellFlags" "IsSpell;HasVerbalComponent;HasSomaticComponent;CannotTargetCharacter;CannotTargetItems;HasHighGroundRangeExtension"
data "RechargeValues" "4-6"
data "PrepareEffect" ""
data "CastEffect" "702acd96-d983-4405-89de-bf1df300fd3e"
data "PositionEffect" "317cb87d-0f5d-440e-b7c0-a5c96e4cd369"


















new entry "MizPact_LOW_RAPHAEL_MONSTER_FORM"
type "StatusData"
data "StatusType" "POLYMORPHED"
// Ascended Fiend
data "DisplayName" "hf2b495faga525g4318g87edgbc6c9f274830;2"
// Raphael has gorged on souls and enhanced his fiendish powers, granting him an even deadlier array of spells and abilities. In this form, <LSTag Type="Status" Tooltip="LOW_RAPHAEL_OVERCHARGE
data "Description" "hcaa17904g742fg4759gb15bg2bed97cce457;3"
data "Icon" "GenericIcon_Intent_Damage"
data "SoundLoop" "Misc_Status_Burning_MO"
data "SoundStop" "CrSpell_Impact_Raphael_TransformEnd; Misc_Status_Burning_MO_Stop"
data "StackId" "LOW_RAPHAEL_MONSTER_FORM"
data "StackPriority" "1"
data "Boosts" "UnlockSpell(Target_LOW_Raphael_Multiattack_Hard)"
data "Passives" "LOW_Raphael_Multiattack_Passive;HellfireDamagePierce_Technical"
data "StatusPropertyFlags" "ApplyToDead"
data "OnApplyFunctors" "RemoveStatus(LOW_RAPHAEL_EXHAUSTED);RemoveStatus(LOW_RAPHAEL_OVERCHARGE);"
data "OnRemoveFunctors" "ApplyStatus(SELF,LOW_RAPHAEL_REMOVE_VFX,100,1);ApplyStatus(LOW_RAPHAEL_EXHAUSTED,100,-1);RemoveStatus(LOW_RAPHAEL_OVERCHARGE_DELAY);ApplyStatus(SELF, WILDSHAPE_TECHNICAL,100,1)"
data "TemplateID" "f5e9cb22-70c4-46ba-bff8-ed9fe8dfb1c8"
data "Rules" "7850235d-f91b-4ca3-a378-3794bac025b9"
data "StatusEffect" "e91f1353-5cff-4319-bf9e-4d7a80808bc9"

new entry "MizPact_LOW_RAPHAEL_MONSTER_FORM"
type "StatusData"
data "StatusType" "POLYMORPHED"
using "LOW_RAPHAEL_MONSTER_FORM"
data "OnApplyFunctors" "RemoveStatus(LOW_RAPHAEL_EXHAUSTED);RemoveStatus(LOW_RAPHAEL_OVERCHARGE);IF(HasStatus('LOW_RAPHAEL_LA_REMAINING_4_CAMBION')):ApplyStatus(LOW_RAPHAEL_LA_REMAINING_4_ASCENDED,100,-1);IF(HasStatus('LOW_RAPHAEL_LA_REMAINING_3_CAMBION')):ApplyStatus(LOW_RAPHAEL_LA_REMAINING_3_ASCENDED,100,-1);IF(HasStatus('LOW_RAPHAEL_LA_REMAINING_2_CAMBION')):ApplyStatus(LOW_RAPHAEL_LA_REMAINING_2_ASCENDED,100,-1);IF(HasStatus('LOW_RAPHAEL_LA_REMAINING_1_CAMBION')):ApplyStatus(LOW_RAPHAEL_LA_REMAINING_1_ASCENDED,100,-1);"
data "OnRemoveFunctors" "ApplyStatus(SELF,LOW_RAPHAEL_REMOVE_VFX,100,1);ApplyStatus(LOW_RAPHAEL_EXHAUSTED,100,-1);RemoveStatus(LOW_RAPHAEL_OVERCHARGE_DELAY);ApplyStatus(SELF, WILDSHAPE_TECHNICAL,100,1);IF(HasStatus('LOW_RAPHAEL_LA_REMAINING_4_ASCENDED')):ApplyStatus(LOW_RAPHAEL_LA_REMAINING_4_CAMBION,100,-1);IF(HasStatus('LOW_RAPHAEL_LA_REMAINING_3_ASCENDED')):ApplyStatus(LOW_RAPHAEL_LA_REMAINING_3_CAMBION,100,-1);IF(HasStatus('LOW_RAPHAEL_LA_REMAINING_2_ASCENDED')):ApplyStatus(LOW_RAPHAEL_LA_REMAINING_2_CAMBION,100,-1);IF(HasStatus('LOW_RAPHAEL_LA_REMAINING_1_ASCENDED')):ApplyStatus(LOW_RAPHAEL_LA_REMAINING_1_CAMBION,100,-1);"


new entry "MizPact_Shout_LOW_Raphael_Transform"
type "SpellData"
data "SpellType" "Shout"
using "Shout_Shapechanger_Doppelganger"
data "Cooldown" "OncePerCombat"
data "SpellProperties" "AI_ONLY:ApplyStatus(SELF,AI_HELPER_BUFF_LARGE, 100, 6);ApplyStatus(LOW_RAPHAEL_MONSTER_FORM,100,1);RestoreResource(SELF,SpellSlot,1,1);GROUND:SurfaceChange(TurnHellfire)"
data "AreaRadius" "20"
data "Icon" "Spell_Raphael_FiendishAscension"
// Fiendish Ascension
data "DisplayName" "hf8d0b35ag2aacg47cdgbb86ga1c6655d5a52;5"
// Harness the energy of a recently shattered Soul Pillar to take on a more powerful infernal form, and consume a new soul for every broken pillar. <br><br>Each time Raphael transforms he may stay in this heightened aspect for longer. 
data "Description" "ha775eefcge581g4b7dg8672g3cbebcecbdc4;6"
data "TooltipStatusApply" ""
data "TooltipOnMiss" ""
data "CastSound" "CrSpell_Cast_Raphael_Transform"
data "TargetSound" "CrSpell_Impact_Raphael_Transform"
data "UseCosts" ""
data "SpellAnimation" "921121ad-e16a-40d2-8e0a-61b0bfaa48b3,,;,,;fd5e6365-f314-42e8-a39b-a041dc56b0e7,,;14294166-95db-46c1-b22a-2b780c2c2790,14294166-95db-46c1-b22a-2b780c2c2790,14294166-95db-46c1-b22a-2b780c2c2790;e6059567-f6b3-40a4-88fb-342243c62718,,;,,;,,;,,;14294166-95db-46c1-b22a-2b780c2c2790,,"
data "SpellAnimationIntentType" "Aggressive"
data "RequirementConditions" "not HasStatus('LOW_RAPHAEL_MONSTER_FORM') and HasStatus('LOW_RAPHAEL_OVERCHARGE') and HasStatus('LOW_RAPHAEL_PILLAR_STATUS_VISUAL_3') and not HasStatus('LOW_RAPHAEL_OVERCHARGE_TIMER')"
data "CastEffect" "51e6d99f-f388-473c-a9cd-be32256fabc6"
data "SpellSoundMagnitude" "Big"
data "Sheathing" "DontChange"

new entry "MizPact_LOW_Raphael_Multiattack_Passive"
type "PassiveData"
using "Multiattack_Drider"
// Multiattack: Last Resort
data "DisplayName" "hadc4882cgdfb1g4604ga839gb244d407056c;1"
// Raphael can <LSTag Type="Spell" Tooltip="Target_LOW_Raphael_Multiattack">Multiattack</LSTag> in his <LSTag Type="Status" Tooltip="LOW_RAPHAEL_MONSTER_FORM">Ascended Fiend</LSTag> form if all of his Soul Pillars have been destroyed and he has no Souls Charges.
data "Description" "h024734b1gab85g408ag9fecgba4a85d8bd8c;2"

new entry "MizPact_Target_LOW_Raphael_Multiattack_Hard"
type "SpellData"
data "SpellType" "Target"
using "Target_LOW_Raphael_Multiattack"
data "SpellProperties" "AI_IGNORE:IF(not HasStatus('ACTION_SURGE', context.Source)):ApplyStatus(SELF,ACTION_SURGE,100,1)"
data "RequirementConditions" "HasStatus('LOW_RAPHAEL_MONSTER_FORM') and HasStatus('LOW_RAPHAEL_NO_PILLARS') and HasStatus('LOW_RAPHAEL_HARDCORE')"
// Once per turn, thanks to his cacodemonic power, Multiattack grants Raphael <LSTag Type="Status" Tooltip="ACTION_SURGE
data "ExtraDescription" "hd47befbfg727eg49fdgaeb3g7287228354f5;2"

new entry "MizPact_Target_LOW_Raphael_Claws"
type "SpellData"
data "SpellType" "Target"
using "Target_Claws_Imp"
data "SpellSuccess" "DealDamage(3d6+UnarmedMeleeAbilityModifier,Slashing)"
data "TooltipDamageList" "DealDamage(3d6+UnarmedMeleeAbilityModifier,Slashing)"

new entry "MizPact_Projectile_LOW_Raphael_HellfireOrb"
type "SpellData"
data "SpellType" "Projectile"
using "Projectile_HellfireOrb_DeathKnight"
data "Cooldown" "OncePerTurn"
data "SpellProperties" "GROUND:CreateSurface(4, 2,Hellfire);SurfaceChange(Ignite);GROUND:SurfaceChange(Melt)"
data "DeathType" "Incinerate"
data "TargetConditions" "Enemy() and not Dead()"
// Ravaging Inferno
data "DisplayName" "h2d34ff19g19f0g41c5gaaeegd5cd1ba01d7b;2"
// Spend [1] souls to hurl an exploding ball of <LSTag Type="Status" Tooltip="BURNING_HELLFIRE">Hellfire</LSTag> that damages all nearby creatures and objects.
data "Description" "h02aac633gf30cg4713g956cg55caf1009dfd;3"
data "DescriptionParams" "2"
data "CastSound" "CrSpell_Cast_PrimordialHell"
data "UseCosts" "ActionPoint:1;SpellSlotsGroup:2:2:1"
data "SpellAnimation" "3ff87abf-1ea1-4c32-aadf-c822d74c7dc0,,;,,;6444d598-3e0e-4a14-902a-c067905a0b87,,;97f8db1e-e873-490a-9c33-8dbb4b97e583,,;d8925ce4-d6d9-400c-92f5-ad772ef7f178,,;,,;eadedcce-d01b-4fbb-a1ae-d218f13aa5d6,,;,,;,,"
data "RechargeValues" "3-6"
data "MemoryCost" "1"
data "RequirementConditions" "HasStatus('LOW_RAPHAEL_MONSTER_FORM')"
data "CastEffect" "6d134da0-3f09-4bfd-928b-70443b382498"
data "Sheathing" "DontChange"

new entry "MizPact_Target_LOW_Raphael_RepelDivinity_SoulDrain"
type "SpellData"
data "SpellType" "Target"
using "Target_VampiricTouch"
data "Level" "6"
data "SpellSchool" ""
data "ConcentrationSpellID" ""
data "Cooldown" "OncePerTurn"
data "SpellProperties" "DealDamage(6d12,Necrotic,Magical); RegainHitPoints(SELF,(6d12)/2)"
data "TargetRadius" "18"
data "RequirementConditions" "not HasStatus('LOW_RAPHAEL_MONSTER_FORM')"
data "SpellRoll" ""
data "SpellSuccess" ""
data "SpellFail" ""
data "TargetConditions" "HasStatus('LOW_RAPHAEL_STUNNED', context.Target) and Enemy() and not Dead()"
// Soul Drain
data "DisplayName" "h91a420c0gcd6cg4fa2g8fb3gac3a27b6d193;2"
// Drain the life force of an <LSTag Type="Status" Tooltip="LOW_RAPHAEL_STUNNED
data "Description" "h2ed0e135ga6ffg46aeg8c08g65e81f01c511;4"
data "DescriptionParams" "DealDamage(6d12, Necrotic);RegainHitPoints(6d12)"
data "ExtraDescription" ""
data "TooltipDamageList" "DealDamage(12d6, Necrotic)"
data "TooltipAttackSave" ""
data "TooltipStatusApply" ""
data "UseCosts" ""
data "SpellFlags" "HasVerbalComponent;HasSomaticComponent;IsSpell;IsMelee;IsHarmful"











new entry "MizPact_Shout_DarkUrge_Slayer"
type "SpellData"
data "SpellType" "Shout"
using "Shout_WildShape"
data "ContainerSpells" ""
data "Cooldown" "OncePerRest"
data "SpellProperties" "IF(not CharacterLevelGreaterThan(9)):ApplyStatus(SLAYER_PLAYER,100,-1); IF(CharacterLevelGreaterThan(9)):ApplyStatus(SLAYER_PLAYER_10,100,-1)"
data "Icon" "Action_DarkUrge"
// Slayer
data "DisplayName" "h7ee059fega56bg48d4g99abg0a1ee50238d1;2"
// Manifest your savage compulsions and assume your sinuously deadly Slayer form. Your Slayer form has [1] (increases to [2] at Level 10).
data "Description" "hdd8b157fgb469g4004g8fd3gac6677d4c088;5"
data "DescriptionParams" "RegainHitPoints(98);RegainHitPoints(153)"
// While in Slayer form, you can't talk or cast spells.<br><br>When your Slayer form drops to 0 <LSTag Tooltip="HitPoints">hit points</LSTag>, you revert to your normal form.
data "ExtraDescription" "h637f3195ge71eg4c06g9c33ge08587bf042b;4"
data "PrepareSound" "CrSpell_Prepare_Slayer_BloodBath"
data "PrepareLoopSound" "CrSpell_Loop_Slayer_BloodBath"
data "CastSound" "Action_Cast_Gen_DarkUrge"
data "TargetSound" "Action_Impact_Gen_DarkUrge"
data "UseCosts" "BonusActionPoint:1"
data "SpellAnimation" "3e235dc6-2b15-4edd-863f-18efb96dbb92,,;,,;7658db84-6394-44ce-a6be-ef1e158f6033,,;721abca5-2d52-4317-82a3-2a2e970a7a16,,;13c4407f-4ffb-4e6a-8a1a-57234fba51dc,,;,,;17aba8de-ced8-4456-90ce-751b99c7866b,,;,,;,,"
data "SpellFlags" "HasSomaticComponent;UnavailableInDialogs"
data "PrepareEffect" "cdbd7d10-08de-4e0f-8d00-08dd7ec82c45"
data "CastEffect" "9e921865-a2ab-44f0-98ff-a649b507737f"





icon:
Action_Monster_Orthon_ExplosiveRetribution


