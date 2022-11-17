while 1:
    i = 0
    filename = input("fájlnév: ")
    body = input("szöveg: ")
    btns = []
    while 1:
        i+=1
        text = input(f"opció {i} text: ")
        if text == "": break
        link = input(f"opció {i} link: ")
        btns.append({"text": text, "link": link})
    if btns:
        print("\nElőző opciók: ")
        for btn in btns:
            print(btn["link"])
        print('\n')
    with open(f"{filename}.game", "w", encoding="UTF-8") as out:
        out.write(body)
        for btn in btns: 
            text = btn["text"]
            link = btn["link"]
            out.write(f"\n|{text}>{link}")