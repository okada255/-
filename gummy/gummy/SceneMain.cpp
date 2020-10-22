//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL/SceneObjManager.h"
#include"GameL/GameHead.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameL/GameHead.h"
#include"ObjBlock.h"
#include"ObjCookie.h"
#include"ObjCandy.h"
#include"ObjChoco.h"
#include"ObjDonatu.h"
#include"ObjGummy.h"
#include"ObjRisu.h"


//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{


}

//初期化メソッド
void CSceneMain::InitScene()
{
	//Blockオブジェクト作成
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//Candyオブジェクト作成
	CObjCandy* objb = new CObjCandy();
	Objs::InsertObj(objb, OBJ_CANDY, 9);

	//Cookieオブジェクト作成
	CObjCookie* objb = new CObjCookie();
	Objs::InsertObj(objb, OBJ_COOKIE, 9);

	//Donatuオブジェクト作成
	CObjDonatu* objb = new CObjDonatu();
	Objs::InsertObj(objb, OBJ_DONATU, 9);

	//Chocoオブジェクト作成
	CObjChoco* objb = new CObjChoco();
	Objs::InsertObj(objb, OBJ_CANDY, 9);

	//Gummyオブジェクト作成
	CObjGummy* objb = new CObjGummy();
	Objs::InsertObj(objb, OBJ_GUMMY, 9);
}

//実行中メソッド
void CSceneMain::Scene()
{

}