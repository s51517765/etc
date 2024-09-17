# SQL問題集

## 動作環境
postgresqlにて動作確認<br>
psql (PostgreSQL) 15.1 (Ubuntu 15.1-1.pgdg22.04+1)

|No.|分類|問題|解答|補足|
|:---|:---|:---|:---|:---|
|1|Login|ログイン|<font color ="#eeeeee">sudo -u postrgres -i</font>|<font color ="#eeeeee">[u] = User, [I] = login</font>|
|2|Login|データベースshopに接続|<font color ="#eeeeee">psql -d shop</font>|<font color ="#eeeeee">[d] = データベース名</font>|
|3|database|データベース全体を表示|<font color ="#eeeeee">select * from shohin;</font>|<font color ="#eeeeee"></font>|
|4|database|新しいテーブルを作成|<font color ="#eeeeee">CREATE TABLE parts ( Id int not null, name varchar(80), type varchar(20));</font>|<font color ="#eeeeee">データベースに接続した状態で実行する。(ex) shop=#</font>|"
|5|database|主キー制約をあとから追加|<font color ="#eeeeee">ALTER TABLE parts ADD PRIMARY KEY(id);</font>|<font color ="#eeeeee"></font>|
|6|database|作成済みのテーブルを表示|<font color ="#eeeeee">\dt</font>|<font color ="#eeeeee">(\)バックスラッシュ、日本語キーボードなら、一番右下にあるやつ</font>|
|7|table|主キーを確認|<font color ="#eeeeee">\d parts;</font>|<font color ="#eeeeee"> "parts_pkey" PRIMARY KEY, btree (bango)</font>|
|8|database|作成済みのテーブルを削除|<font color ="#eeeeee">drop table parts;</font>|<font color ="#eeeeee"></font>|
|9|select|shouhin_bunrui が衣服であるものだけ抽出|<font color ="#eeeeee">select * from shohin where shohin_bunrui='衣服'</font>|<font color ="#eeeeee"></font>|
|10|select|shiire_tankaで種類ごとにカウントする|<font color ="#eeeeee">select shiire_tanka, count(*) from shohin group by shiire_tanka;</font>|<font color ="#eeeeee"></font>|
|11|select|shiire_tankaで種類ごとにカウントする（別解）|<font color ="#eeeeee">select count (distinct shiire_tanka) from shohin</font>|<font color ="#eeeeee"></font>|
|12|select|shiire_tanka がnullでないものを抽出|<font color ="#eeeeee">select * from shohin where shiire_tanka is null;</font>|<font color ="#eeeeee"></font>|
|13|data|次のデータを追加 '0012','穴あけパンチ', '事務用品',500,320,'2009-09-11'|<font color ="#eeeeee">insert into shohin values('0012','穴あけパンチ','事務用品',500,320,'2009-09-11');</font>|<font color ="#eeeeee">文字列は''シングルクォートで囲む</font>|
|14|data|先のデータを削除|<font color ="#eeeeee">delete from shohin where shohin_id = '0012';</font>|<font color ="#eeeeee"></font>|
|15|select|重複を除外してshohin_meiを取得|<font color ="#eeeeee">select distinct shohin_mei from shohin;</font>|<font color ="#eeeeee"></font>|
|16|calculate|販売単価を2倍して表示|<font color ="#eeeeee">select shohin_mei, hanbai_tanka *2 as "hanbaitanka_x2" from shohin;</font>|<font color ="#eeeeee"></font>|
|17|select|shouhin_bunruiとshiire_tankaの組み合わせを抽出|<font color ="#eeeeee">select distinct shohin_bunrui, shiire_tanka from shohin;</font>|<font color ="#eeeeee"></font>|
|18|column|varchar(10)型で列を追加|<font color ="#eeeeee">alter table shohin add column memo2 varchar(10);</font>|<font color ="#eeeeee"></font>|
|19|column|上記の削除|<font color ="#eeeeee">alter table shohin drop column memo2;</font>|<font color ="#eeeeee"></font>|
|20|column|列を追加（Not null）|<font color ="#eeeeee">alter table jyushoroku add column jyusho varchar(100) not null</font>|<font color ="#eeeeee"></font>|
|21|table|テーブル名の変更|<font color ="#eeeeee">alter table shohi rename to Shohin</font>|<font color ="#eeeeee"></font>|
|22|table|上記を戻す（再変更）|<font color ="#eeeeee">↑</font>|<font color ="#eeeeee"></font>|
|23|select|登録日2009-09-27より新しいものを抽出|<font color ="#eeeeee">select * from shohin where torokubi>'2009-09-27';</font>|<font color ="#eeeeee"></font>|
|24|select|hanbai_tankaの平均を商品分類ごとに出力|<font color ="#eeeeee">select shohin_bunrui, avg(hanbai_tanka) from shohin group by shohin_bunrui;</font>|<font color ="#eeeeee"></font>|
|25|calculate|hanbai_tankaの平均が2000円以上となる商品分類を抽出|<font color ="#eeeeee">select shohin_bunrui, avg(hanbai_tanka) from shohin group by shohin_bunrui having avg(hanbai_tanka)>=2000;</font>|<font color ="#eeeeee"></font>|
|26|calculate|キッチン用品の販売価格の平均は？|<font color ="#eeeeee">select shohin_bunrui, avg(hanbai_tanka) from shohin group by shohin_bunrui;</font>|<font color ="#eeeeee"></font>|
|27|select|衣服のデータ数は？|<font color ="#eeeeee">select shohin_bunrui,count(*) from shohin where shohin_bunrui='衣服' group by shohin_bunrui;</font>|<font color ="#eeeeee"></font>|
|28|select|衣服のデータ数は？（別解）|<font color ="#eeeeee">select shohin_bunrui,count(*) from shohin group by shohin_bunrui having shohin_bunrui='衣服';</font>|<font color ="#eeeeee"></font>|
|29|select|tableをhanbai_tanka順に並べ替えよ|<font color ="#eeeeee">select * from shohin order by hanbai_tanka;</font>|<font color ="#eeeeee"></font>|
|30|select|tableをhanbai_tanka高いものから順に並べ替えよ|<font color ="#eeeeee">select * from shohin order by hanbai_tanka desc;</font>|<font color ="#eeeeee"></font>|
|31|select|tableをhanbai_tanka高いものから順にかつ、ID順に並べ替えよ|<font color ="#eeeeee">select * from shohin order by hanbai_tanka desc,shohin_id;</font>|<font color ="#eeeeee"></font>|
|32|select|shohin_bunrui毎に販売価格と仕入れ価格の合計を表示する|<font color ="#eeeeee">select shohin_bunrui ,sum(hanbai_tanka),sum(shiire_tanka) from shohin group by shohin_bunrui;</font>|<font color ="#eeeeee"></font>|
|33|select|shohin_bunrui毎に合計したとき、販売価格の合計が仕入れ価格の合計の1.5以上のものを表示せよ|<font color ="#eeeeee">select shohin_bunrui ,sum(hanbai_tanka),sum(shiire_tanka) from shohin group by shohin_bunrui having sum(hanbai_tanka)>sum(shiire_tanka)*1.5;</font>|<font color ="#eeeeee"></font>|
|34|select|販売単価から仕入れ単価を引いたものを利益と名付け、商品名とともに表示せよ|<font color ="#eeeeee">select shohin_mei,hanbai_tanka ,hanbai_tanka -shiire_tanka as rieki from shohin;</font>|<font color ="#eeeeee"></font>|
|35|select|商品分類ごとにレコード数を出力|<font color ="#eeeeee">select shohin_bunrui, count(*) from shohin group by shohin_bunrui;</font>|<font color ="#eeeeee"></font>|
|36|select|商品分類が事務用品であるものを販売単価ごとにカウントせよ|<font color ="#eeeeee">select hanbai_tanka ,count(*) from shohin where shohin_bunrui='事務用品' group by hanbai_tanka;</font>|<font color ="#eeeeee"></font>|
