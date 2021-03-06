#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "../../VisibleRect.h"
#include "../../testBasic.h"
#include "cocostudio/CocoStudio.h"

#if ENABLE_PHYSICS_BOX2D_DETECT
#include "../../Box2DTestBed/GLES-Render.h"
#include "Box2D/Box2D.h"
#elif ENABLE_PHYSICS_CHIPMUNK_DETECT
#include "chipmunk.h"
#endif

class ArmatureTestScene : public TestScene
{
public: 
	ArmatureTestScene(bool bPortrait = false);

	virtual void runThisTest();

	// The CallBack for back to the main menu scene
	virtual void MainMenuCallback(Object* pSender);
};

enum {
	TEST_ASYNCHRONOUS_LOADING = 0,
	TEST_COCOSTUDIO_WITH_SKELETON,
	TEST_DRAGON_BONES_2_0,
	TEST_PERFORMANCE,
	TEST_CHANGE_ZORDER,
	TEST_ANIMATION_EVENT,
	TEST_PARTICLE_DISPLAY,
	TEST_USE_DIFFERENT_PICTURE,
	TEST_BCOLLIDER_DETECTOR,
	TEST_BOUDINGBOX,
	TEST_ANCHORPOINT,
	TEST_ARMATURE_NESTING,

	TEST_LAYER_COUNT
};

class ArmatureTestLayer : public Layer
{
public:
	virtual void onEnter();
	virtual void onExit();

	virtual std::string title();
	virtual std::string subtitle();

	virtual void restartCallback(Object* pSender);
	virtual void nextCallback(Object* pSender);
	virtual void backCallback(Object* pSender);

	virtual void draw();

protected:
	MenuItemImage *restartItem;
	MenuItemImage *nextItem;
	MenuItemImage *backItem;
};


class TestAsynchronousLoading : public ArmatureTestLayer
{
public:
	virtual void onEnter();
	virtual std::string title();
	virtual std::string subtitle();

	void dataLoaded(float percent);
};

class TestCSWithSkeleton : public ArmatureTestLayer
{
	virtual void onEnter();
	virtual std::string title();
};


class TestDragonBones20 : public ArmatureTestLayer
{
public:
	virtual void onEnter();
	virtual std::string title();
};


class TestPerformance : public ArmatureTestLayer
{
public:
	~TestPerformance();

	virtual void onEnter();
	virtual std::string title();
	virtual std::string subtitle();
	virtual void addArmature(cocostudio::Armature *armature);
	void update(float delta);

	int armatureCount;

	int frames;
	float times;
	float lastTimes;
	bool generated;
};


class TestChangeZorder : public ArmatureTestLayer
{
	virtual void onEnter();
	virtual std::string title();
	void changeZorder(float dt);

	int currentTag;
};


class TestAnimationEvent : public ArmatureTestLayer
{
public:

	virtual void onEnter();
	virtual std::string title();
	void animationEvent(cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const char *movementID);
	void callback1();
	void callback2();

	cocostudio::Armature *armature;
};

class TestUseMutiplePicture : public ArmatureTestLayer
{
	virtual void onEnter();
	virtual void onExit();
	virtual std::string title();
	virtual std::string subtitle();
	void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);

	int displayIndex;
	cocostudio::Armature *armature;
};

class TestParticleDisplay : public ArmatureTestLayer
{
	virtual void onEnter();
	virtual void onExit();
	virtual std::string title();
	virtual std::string subtitle();
	void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);

	int animationID;
	cocostudio::Armature *armature;
};




#if ENABLE_PHYSICS_BOX2D_DETECT

class ContactListener;

class TestColliderDetector : public ArmatureTestLayer
{
public:
	~TestColliderDetector();

	virtual void onEnter();
	virtual void onExit();
	virtual std::string title();
	virtual void draw();
	virtual void update(float delta);

	void onFrameEvent(cocostudio::Bone *bone, const char *evt, int originFrameIndex, int currentFrameIndex);

	void initWorld();


	cocostudio::Armature *armature;
	cocostudio::Armature *armature2;

	cocos2d::extension::PhysicsSprite *bullet;

	b2World *world;
	ContactListener *listener;
	GLESDebugDraw *debugDraw;
};


#elif ENABLE_PHYSICS_CHIPMUNK_DETECT


class TestColliderDetector : public ArmatureTestLayer
{
public:
	~TestColliderDetector();

	virtual void onEnter();
	virtual void onExit();
	virtual std::string title();
	virtual void update(float delta);

	void onFrameEvent(cocostudio::Bone *bone, const char *evt, int originFrameIndex, int currentFrameIndex);

	void initWorld();


	cocostudio::Armature *armature;
	cocostudio::Armature *armature2;

	cocos2d::extension::PhysicsSprite *bullet;


	cpSpace *space;

	static int beginHit(cpArbiter *arb, cpSpace *space, void *unused);
	static void endHit(cpArbiter *arb, cpSpace *space, void *unused);

	void destroyCPBody(cpBody *body);
};
#endif





class TestBoundingBox : public ArmatureTestLayer
{
public:
	virtual void onEnter();
	virtual std::string title();
	virtual void draw();

	cocostudio::Armature *armature;
	Rect rect;
};

class TestAnchorPoint : public ArmatureTestLayer
{
public:
	virtual void onEnter();
	virtual std::string title();
};

class TestArmatureNesting : public ArmatureTestLayer
{
public:
	virtual void onEnter();
	virtual void onExit();
	virtual std::string title();
	void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);

	cocostudio::Armature *armature;
	int weaponIndex;
};
#endif  // __HELLOWORLD_SCENE_H__