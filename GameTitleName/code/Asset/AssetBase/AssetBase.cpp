#include<DxLib.h>

#include "AssetBase.h"

AssetBase::AssetBase()
	:holdHandle(-1)
	, dupHandle(-1)
	, assetType("")
	, jsonFile("")
{
	//処理なし
}

AssetBase::~AssetBase()
{
	//処理なし
}

void AssetBase::LoadJsonFile(std::string fileName)
{
	//ファイル読み込み
	//ifstream ファイルの中身を読み込む
	//ifsに読み込み結果の状態(失敗or成功)が入る
	std::ifstream ifs(fileName.c_str());

	//ファイルが存在したら解析
	if (ifs.good())
	{
		rapidjson::IStreamWrapper isw(ifs);

		doc.ParseStream(isw);
	}
	ifs.close();

	//アセットタイプ設定
	rapidjson::Value::ConstMemberIterator type = doc.MemberBegin();
	assetType = type->name.GetString();
}

const int AssetBase::GetHandle(std::string handleName)
{
	//取得したいハンドルを探す
	auto iter = handle.find(handleName);
	//見つかったら
	if (iter != handle.end())
	{
			//ハンドルを返す
			return handle[handleName];
	}

	//返せなかったら-1を返す
	return -1;
}