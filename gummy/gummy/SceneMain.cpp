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
#include"ObjBlock.h"


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

	//Blockオブジェクト作成
	CObjCandy* objb = new CObjCandy();
	Objs::InsertObj(objb, OBJ_CANDY, 9);
}

//実行中メソッド
void CSceneMain::Scene()
{

}