#pragma once
#include <BWAPI.h>
#include <BWTA/Chokepoint.h>
#include <BWTA/Polygon.h>
#include <BWTA/Region.h>
#include <BWTA/BaseLocation.h>
#include <BWTA/RectangleArray.h>
namespace BWTA
{	
	/// Reads the contents of the map in to BWTA. 
	///		This was added so analyze() can be executed in another thread. 
	void readMap();
	/// Before any other global functions can be called, the map must first be analyzed. 
	///		Analyzing a starcraft map can take a long time, depending on your computer, 
	///		so BWTA also automatically saves the results to a file when it is done. 
	///		When you call analyze on the same map, 
	///		will see that the results file for that map already exists, 
	///		and load the results from file, rather than re-analyze the map. 
	void analyze();
	/// Returns the set of regions in the map. 
	const std::set<Region*>& getRegions();
	/// Returns the set of chokepoints in the map. 
	const std::set<Chokepoint*>& getChokepoints();
	/// Returns the set of base locations on the map. 
	const std::set<BaseLocation*>& getBaseLocations();
	/// Returns the set of base locations that are start locations. 
	const std::set<BaseLocation*>& getStartLocations();
	/// Returns the set of unwalkable polygons.
	const std::set<Polygon*>& getUnwalkablePolygons();

	/// Given a pointer to a BWAPI::Player object, 
	///		this function returns a pointer to the player's starting base location. 
	BaseLocation* getStartLocation(BWAPI::Player* player);
	
	/// Returns the region that the tile position is inside.
	///		Returns NULL if the tile position is not inside any region.
	Region* getRegion(int x, int y);
	/// Returns the region that the tile position is inside.
	///		Returns NULL if the tile position is not inside any region.
	Region* getRegion(BWAPI::TilePosition tileposition);

	/// Returns the nearest chokepoint (in ground/walking distance). 
	///		Returns NULL if no chokepoint is reachable from the given tile position 
	///		(such as in an island component with no chokepoints). 
	Chokepoint* getNearestChokepoint(int x, int y);
	/// Returns the nearest chokepoint (in ground/walking distance). 
	///		Returns NULL if no chokepoint is reachable from the given tile position 
	///		(such as in an island component with no chokepoints). 
	Chokepoint* getNearestChokepoint(BWAPI::TilePosition tileposition);

	/// Returns the nearest base location(in ground/walking distance). 
	///		Returns NULL if no base location is reachable from the given tile position. 
	BaseLocation* getNearestBaseLocation(int x, int y);
	/// Returns the nearest base location(in ground/walking distance). 
	///		Returns NULL if no base location is reachable from the given tile position. 
	BaseLocation* getNearestBaseLocation(BWAPI::TilePosition tileposition);

	/// Returns the nearest unwalkable polygon. 
	///		Note: The border of the map is not considered an unwalkable polygon. 
	Polygon* getNearestUnwalkablePolygon(int x, int y);
	/// Returns the nearest unwalkable polygon. 
	///		Note: The border of the map is not considered an unwalkable polygon. 
	Polygon* getNearestUnwalkablePolygon(BWAPI::TilePosition tileposition);
	/// Returns the nearest position that is on the boundary of an unwalkable polygon, or border of the map. 
	BWAPI::Position getNearestUnwalkablePosition(BWAPI::Position position);

	/// Returns true if there exists a static path between the two given tile positions. 
	bool isConnected(int x1, int y1, int x2, int y2);
	/// Returns true if there exists a static path between the two given tile positions. 
	bool isConnected(BWAPI::TilePosition a, BWAPI::TilePosition b);

	/// Returns the ground distance between the two given tile positions. 
	double getGroundDistance(BWAPI::TilePosition start, BWAPI::TilePosition end);
	/// Returns the tile position in the given set that is closest to the given tile position,
	///		along with the ground distance to that tile position. 
	std::pair<BWAPI::TilePosition, double> getNearestTilePosition(BWAPI::TilePosition start, std::set<BWAPI::TilePosition>& targets);
	/// Returns the distance to each target tile position. 
	std::map<BWAPI::TilePosition, double> getGroundDistances(BWAPI::TilePosition start, std::set<BWAPI::TilePosition>& targets);
	/// Fills up the given RectangleArray distance map with the distance from the given tile position. 
	///		Tiles not reachable from the given tile position will be set to -1. 
	void getGroundDistanceMap(BWAPI::TilePosition start, RectangleArray<double>& distanceMap);

	/// Returns the shortest path from the start tile position to the end tile position. 
	///		If no path exists, the vector will be empty. 
	std::vector<BWAPI::TilePosition> getShortestPath(BWAPI::TilePosition start, BWAPI::TilePosition end);
	/// Returns the shortest path from the start tile position to the closest target tile position. 
	///		If no path exists to any of the target tile positions, the vector will be empty. 
	std::vector<BWAPI::TilePosition> getShortestPath(BWAPI::TilePosition start, std::set<BWAPI::TilePosition>& targets);

}