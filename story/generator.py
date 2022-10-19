while 1:
    i = 0
    body = input("szöveg: ")
    filename = input("fájlnév: ")
    btns = []
    while 1:
        i+=1
        text = input(f"opció {i} text: ")
        if text == "": break
        link = input(f"opció {i} link: ")
        btns.append({"text": text, "link": link})

    with open(f"story/{filename}.game", "w", encoding="UTF-8") as out:
        out.write(body)
        for btn in btns: 
            text = btn["text"]
            link = btn["link"]
            out.write(f"\n|{text}>{link}")