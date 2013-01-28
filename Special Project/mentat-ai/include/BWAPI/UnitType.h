#pragma once
#include <string>
#include <map>
#include <set>
#include <BWAPI/Race.h>
#include <BWAPI/UnitSizeType.h>
namespace BWAPI
{
	class TechType;
	class UpgradeType;
	class WeaponType;
	class UnitType
	{
	public:
		UnitType();
		UnitType(int id);
		UnitType(const UnitType& other);
		UnitType& operator=(const UnitType& other);
		bool operator==(const UnitType& other) const;
		bool operator!=(const UnitType& other) const;
		bool operator<(const UnitType& other) const;
		
		// Returns a unique ID for this unit type
		int getID() const;
		std::string getName() const;
		
		/// Returns the rank/sublabel of the unit, eg, Captain.
		std::string getSubLabel() const;
		Race getRace() const;

		
		/// Returns what makes the unit.
		///		The int half of the pair will always be 1,
		///		except in cases like the Dark Archon, where it'll be 2.
		/// Units that can't be created, like critters and minerals will return
		///		(UnitTypes::None, 0)
		const std::pair< const UnitType*, int > whatBuilds() const;
		
		/// Returns the units that the player is required to have
		///		before he can train or build the given unit type.
		/// UnitTypes::TerranBattleCruiser.requiredUnits() will return
		///		a map containing three keys: UnitTypes::Terran_Starport,
		///		UnitTypes::Terran_Control_Tower, and UnitTypes::Terran_Physics_Lab
		const std::map< const UnitType*, int >& requiredUnits() const;
		
		/// Only required for Zerg_Lurker and Zerg_Lurker_Egg
		///	The required tech is TechTypes::Lurker_Aspect
		const TechType* requiredTech() const;
		
		/// Returns the set of tech types this unit can use,
		///	provided that they've been researched and the unit has the energy.
		const std::set< const TechType* >& abilities() const;
		
		/// Returns the set of upgrade types that can affect this unit.
		const std::set< const UpgradeType* >& upgrades() const;
		
		/// Returns the upgrade that increases the unit's armor,
		///		or UpgradeTypes::None if no upgrade increases this unit's armor.
		/// UnitTypes::Terran_Marine.armorUpgrade() will return a pointer to
		///		UpgradeTypes::Terran_Infantry_Armor
		const UpgradeType* armorUpgrade() const;

		int maxHitPoints() const;
		int maxShields() const;
		int maxEnergy() const;
		int armor() const;

		int mineralPrice() const;
		int gasPrice() const;
		/// Returns the number of frames needed to build this unit.
		int buildTime() const;

		/// Returns the supply required by this unit.
		///	Remember that the number it gives you will be double what you see in-game.
		///	This is because zerglings take up .5 supply.
		int supplyRequired() const;
		
		/// Returns the supply provided by this unit.
		///	Remember that the number it gives you will be double what you see in-game.
		///	This is because zerglings take up .5 supply.
		int supplyProvided() const;
		
		/// Returns the amount of space this unit takes up in a bunker or transport.
		int spaceRequired() const;
		int spaceProvided() const;
		
		/// Returns the score used in the post-game screen to calculate points.
		int buildScore() const;
		
		/// Returns the score used in the post-game screen to calculate points.
		int destroyScore() const;

		/// Returns the size of the unit - either Small, Medium, Large, or Independent.
		UnitSizeType size() const;
		int tileWidth() const;
		int tileHeight() const;
		
		/// Distance from the center of the unit to the left edge of the unit, measured in pixels. 
		int dimensionLeft() const;
		/// Distance from the center of the unit to the top edge of the unit, measured in pixels. 
		int dimensionUp() const;
		/// Distance from the center of the unit to the right edge of the unit, measured in pixels. 
		int dimensionRight() const;
		/// Distance from the center of the unit to the bottom edge of the unit, measured in pixels. 
		int dimensionDown() const;

		/// Returns the range at which the unit will start targeting enemy units, measured in pixels.
		int seekRange() const;
		/// Returns how far the un-upgraded unit type can see into the fog of war, measured in pixels. 
		int sightRange() const;
		
		/// Returns the unit's ground weapon
		///	Allows you to see range, what type of damage it deals, etc.
		const WeaponType* groundWeapon() const;
		int maxGroundHits() const;
		
		/// Returns the unit's air weapon
		///	Allows you to see range, what type of damage it deals, etc.
		const WeaponType* airWeapon() const;
		int maxAirHits() const;

		/// Returns the non-upgraded unit's top speed.
		///	For buildings that can fly, this returns their speed when lifted off.
		double topSpeed() const;
		
		/// Returns how fast the unit can accelerate to its top speed.
		///	From the site: What units this quantity is measured in is currently unknown.
		int acceleration() const;
		
		/// Related to how fast the unit can halt.
		///	From the site: What units this quantity is measured in is currently unknown.
		int haltDistance() const;
		
		/// Related to how fast the unit can turn.
		///	What units this quantity is measured in is currently unknown. 
		int turnRadius() const;

		/// Returns true if the unit can train other units.
		/// For example, UnitTypes::Terran_Barracks.canProduce() will return true,
		///		while UnitTypes::Terran_Marine.canProduce() will return false.
		/// This is also true for two non-building units:
		///		Protoss Carrier (can produce interceptors)
		///		and Protoss Reaver (can produce scarabs).
		bool canProduce() const;
		
		/// Returns true if the unit can attack (either ground or air).
		/// Returns false for units that can only inflict damage via special abilities,
		///		such as Protoss High Templar. 
		bool canAttack() const;
		
		/// Returns true if the unit can move.
		/// Note that buildings will return false,
		///		even Terran buildings which can move once lifted. 
		bool canMove() const;

		bool isFlyer() const;
		bool regeneratesHP() const;
		/// Returns true if the unit type is capable of casting spells / using technology.
		bool isSpellcaster() const;
		bool hasPermanentCloak() const;
		bool isInvincible() const;
		bool isOrganic() const;
		bool isMechanical() const;
		bool isRobotic() const;

		/// Returns true for the seven units that can detect cloaked units.
		bool isDetector() const;
		
		/// Returns true for geysers, refineries, and mineral fields.
		bool isResourceContainer() const;
		bool isResourceDepot() const;
		bool isRefinery() const;
		bool isWorker() const;
		bool requiresPsi() const;
		bool requiresCreep() const;
		bool isTwoUnitsInOneEgg() const;
		bool isBurrowable() const;
		
		/// Returns true for units that can be cloaked
		///		Terran Ghost and Terran Wraith.
		/// Does not include units which have permanent cloak:
		///		Protoss Observer and Protoss Dark Templar. 
		bool isCloakable() const;
		
		/// Returns true if the unit is a building.
		///		Also true for mineral field and vespene geyser. 
		bool isBuilding() const;
		bool isAddon() const;
		bool isFlyingBuilding() const;
		bool isNeutral() const;
	private:
		int id;
	};
	namespace UnitTypes
	{
		UnitType getUnitType(std::string& name);
		std::set<UnitType>& allUnitTypes();
		void init();
		extern const UnitType Terran_Marine;
		extern const UnitType Terran_Ghost;
		extern const UnitType Terran_Vulture;
		extern const UnitType Terran_Goliath;
		extern const UnitType Terran_Siege_Tank_Tank_Mode;
		extern const UnitType Terran_SCV;
		extern const UnitType Terran_Wraith;
		extern const UnitType Terran_Science_Vessel;
		extern const UnitType Terran_Dropship;
		extern const UnitType Terran_Battlecruiser;
		extern const UnitType Terran_Vulture_Spider_Mine;
		extern const UnitType Terran_Nuclear_Missile;
		extern const UnitType Terran_Siege_Tank_Siege_Mode;
		extern const UnitType Terran_Firebat;
		extern const UnitType Spell_Scanner_Sweep;
		extern const UnitType Terran_Medic;
		extern const UnitType Zerg_Larva;
		extern const UnitType Zerg_Egg;
		extern const UnitType Zerg_Zergling;
		extern const UnitType Zerg_Hydralisk;
		extern const UnitType Zerg_Ultralisk;
		extern const UnitType Zerg_Broodling;
		extern const UnitType Zerg_Drone;
		extern const UnitType Zerg_Overlord;
		extern const UnitType Zerg_Mutalisk;
		extern const UnitType Zerg_Guardian;
		extern const UnitType Zerg_Queen;
		extern const UnitType Zerg_Defiler;
		extern const UnitType Zerg_Scourge;
		extern const UnitType Zerg_Infested_Terran;
		extern const UnitType Terran_Valkyrie;
		extern const UnitType Zerg_Cocoon;
		extern const UnitType Protoss_Corsair;
		extern const UnitType Protoss_Dark_Templar;
		extern const UnitType Zerg_Devourer;
		extern const UnitType Protoss_Dark_Archon;
		extern const UnitType Protoss_Probe;
		extern const UnitType Protoss_Zealot;
		extern const UnitType Protoss_Dragoon;
		extern const UnitType Protoss_High_Templar;
		extern const UnitType Protoss_Archon;
		extern const UnitType Protoss_Shuttle;
		extern const UnitType Protoss_Scout;
		extern const UnitType Protoss_Arbiter;
		extern const UnitType Protoss_Carrier;
		extern const UnitType Protoss_Interceptor;
		extern const UnitType Protoss_Reaver;
		extern const UnitType Protoss_Observer;
		extern const UnitType Protoss_Scarab;
		extern const UnitType Critter_Rhynadon;
		extern const UnitType Critter_Bengalaas;
		extern const UnitType Critter_Scantid;
		extern const UnitType Critter_Kakaru;
		extern const UnitType Critter_Ragnasaur;
		extern const UnitType Critter_Ursadon;
		extern const UnitType Zerg_Lurker_Egg;
		extern const UnitType Zerg_Lurker;
		extern const UnitType Spell_Disruption_Web;
		extern const UnitType Terran_Command_Center;
		extern const UnitType Terran_Comsat_Station;
		extern const UnitType Terran_Nuclear_Silo;
		extern const UnitType Terran_Supply_Depot;
		extern const UnitType Terran_Refinery;
		extern const UnitType Terran_Barracks;
		extern const UnitType Terran_Academy;
		extern const UnitType Terran_Factory;
		extern const UnitType Terran_Starport;
		extern const UnitType Terran_Control_Tower;
		extern const UnitType Terran_Science_Facility;
		extern const UnitType Terran_Covert_Ops;
		extern const UnitType Terran_Physics_Lab;
		extern const UnitType Terran_Machine_Shop;
		extern const UnitType Terran_Engineering_Bay;
		extern const UnitType Terran_Armory;
		extern const UnitType Terran_Missile_Turret;
		extern const UnitType Terran_Bunker;
		extern const UnitType Special_Crashed_Norad_II;
		extern const UnitType Special_Ion_Cannon;
		extern const UnitType Zerg_Infested_Command_Center;
		extern const UnitType Zerg_Hatchery;
		extern const UnitType Zerg_Lair;
		extern const UnitType Zerg_Hive;
		extern const UnitType Zerg_Nydus_Canal;
		extern const UnitType Zerg_Hydralisk_Den;
		extern const UnitType Zerg_Defiler_Mound;
		extern const UnitType Zerg_Greater_Spire;
		extern const UnitType Zerg_Queens_Nest;
		extern const UnitType Zerg_Evolution_Chamber;
		extern const UnitType Zerg_Ultralisk_Cavern;
		extern const UnitType Zerg_Spire;
		extern const UnitType Zerg_Spawning_Pool;
		extern const UnitType Zerg_Creep_Colony;
		extern const UnitType Zerg_Spore_Colony;
		extern const UnitType Zerg_Sunken_Colony;
		extern const UnitType Special_Overmind_With_Shell;
		extern const UnitType Special_Overmind;
		extern const UnitType Zerg_Extractor;
		extern const UnitType Special_Mature_Chrysalis;
		extern const UnitType Special_Cerebrate;
		extern const UnitType Special_Cerebrate_Daggoth;
		extern const UnitType Protoss_Nexus;
		extern const UnitType Protoss_Robotics_Facility;
		extern const UnitType Protoss_Pylon;
		extern const UnitType Protoss_Assimilator;
		extern const UnitType Protoss_Observatory;
		extern const UnitType Protoss_Gateway;
		extern const UnitType Protoss_Photon_Cannon;
		extern const UnitType Protoss_Citadel_of_Adun;
		extern const UnitType Protoss_Cybernetics_Core;
		extern const UnitType Protoss_Templar_Archives;
		extern const UnitType Protoss_Forge;
		extern const UnitType Protoss_Stargate;
		extern const UnitType Special_Stasis_Cell_Prison;
		extern const UnitType Protoss_Fleet_Beacon;
		extern const UnitType Protoss_Arbiter_Tribunal;
		extern const UnitType Protoss_Robotics_Support_Bay;
		extern const UnitType Protoss_Shield_Battery;
		extern const UnitType Special_Khaydarin_Crystal_Form;
		extern const UnitType Special_Protoss_Temple;
		extern const UnitType Special_XelNaga_Temple;
		extern const UnitType Resource_Mineral_Field;
		extern const UnitType Resource_Vespene_Geyser;
		extern const UnitType Special_Warp_Gate;
		extern const UnitType Special_Psi_Disrupter;
		extern const UnitType Special_Power_Generator;
		extern const UnitType Special_Overmind_Cocoon;
		extern const UnitType Spell_Dark_Swarm;
		extern const UnitType None;
		extern const UnitType Unknown;

	}
}
