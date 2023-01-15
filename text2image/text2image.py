from PIL import Image, ImageDraw, ImageFont
import datetime
import platform
os = platform.system()
print(os)
while True:
    print("Input text...")
    text = input()
    if text == "exit":
        break
    if text == "":
        text = "無いぞ知名度SCSK"
    text += "\n________________________________________"
    # RGB, 画像サイズ, 背景色を設定
    im = Image.new("RGBA", (2170, 1215), (0, 0, 0, 0))  # (x,y),(R,G,B,A)
    draw = ImageDraw.Draw(im)
    # siten x siten y shuuten x shuuten y
    draw.rectangle((0, 1110, 2170, 1215), fill=(0, 0, 0, 128))

    # PCローカルのフォントへのパスと、フォントサイズを指定
    if os == "Linux":
        fontsize = 100
        font = ImageFont.truetype(
            "/usr/share/fonts/opentype/noto/NotoSerifCJK-SemiBold.ttc", fontsize)
    else:
        fontsize = 80
        font = ImageFont.truetype('C:/Windows/Fonts/meiryob.ttc', fontsize)
    # 描画位置、描画する文字、文字色、フォントを指定
    # 改行は\n
    # draw.multiline_text((0, 0), text, fill=(255, 255, 0), font=font, align='center')  # Yellow
    draw.multiline_text((0, 1110), text, fill=(255, 255, 0),
                        font=font, align='center')  # Yellow

    # ファイルに出力
    time = datetime.datetime.now().strftime('%Y%m%d%H%M%S')
    im.save("img/"+time+".png")
