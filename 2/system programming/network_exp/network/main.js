var gidCurEvent = "";
var gc_scale = 1;
var is_laser_pointer = true;
var is_CMD = false;
var is_Hidden = true;
var gWindow;
var gDoc;
var scriptParentURL;


console.log("main.js version 1.1.0, written by Hiroki Shibata. October 2019");

HTMLElement.prototype.queryChildren = function (selector) {
    this.setAttribute("data-uuid_edbquq6t5xxb", "o8nc13nx4co9anroidmt9");
    let lo = this.querySelectorAll("[data-uuid_edbquq6t5xxb=o8nc13nx4co9anroidmt9] " + selector);
    this.removeAttribute("data-uuid_edbquq6t5xxb");
    return lo;
}
function setPage(prevID) {
    let tEvent = gDoc.getElementById(gidCurEvent);
    if (tEvent != null) {
        if (tEvent.tagName.toLowerCase() == "slide") {
            tEvent.scrollIntoView(true);
            let oVideos = tEvent.queryChildren("> video");
            for (let i = 0; i < oVideos.length; i++) {
                oVideos[i].currentTime = 0;
                oVideos[i].pause();
            }
        } else if (tEvent.tagName.toLowerCase() == "figure") {
            let oVideos = tEvent.querySelectorAll("video");
            for (let i = 0; i < oVideos.length; i++) {
                oVideos[i].currentTime = 0;
                oVideos[i].play();
            }

        }
    }
}

function change_to_printingMode() {
    is_laser_pointer = false;
    enableLaserPointer();
    Array.prototype.forEach.call(gDoc.querySelectorAll("h1, h2, h3, h4, h5"), function (elem) {
        elem.style.display = "none";
    });
    Array.prototype.forEach.call(gDoc.querySelectorAll("article"), function (elem) {
        elem.style.border = "0.2rem solid #000000";
    });
}
function nextEvent() {
    let oEvent = gDoc.getElementById(gidCurEvent);
    if (oEvent == null) {
        oEvent = gDoc.querySelector("slide");
    }
    let nid = oEvent.getAttribute("data-xNextEventID");
    if (nid != null) {
        gidCurEvent = nid;

        let oVideos = oEvent.querySelectorAll("video");
        for (let i = 0; i < oVideos.length; i++) {
            oVideos[i].pause();
        }
        setPage();
    }
}
function previousEvent() {
    let oEvent = gDoc.getElementById(gidCurEvent);
    if (oEvent == null) {
        oEvent = gDoc.querySelector("slide");
    }
    let pid = oEvent.getAttribute("data-xPreviousEventID");
    if (pid != null) {
        gidCurEvent = pid;

        setPage();
    }
}
function setScales(time) {
    gWindow.setTimeout(function () {
        let h;
        let width = gWindow.innerWidth / 16 * 8.97;

        if (gWindow.innerHeight > width) {
            h = width;
        }
        else {
            h = gWindow.innerHeight;
        }
        gDoc.documentElement.style.fontSize = gc_scale * h * 0.01 + "px";

        setPage();
    }, time);
}
function exitHandler() {

    if (gDoc.fullscreenElement === null) {
        /* Run code on exit */
        setScales(250);
    }
}

function enableLaserPointer() {
    let elem = gDoc.getElementById("i_mousepointer");
    if (is_laser_pointer) {
        elem.style.display = "block";
    }
    else {
        elem.style.display = "none";
    }
}

function pointerMove(e) {
    let elem = gDoc.getElementById("i_mousepointer");
    let bBox = elem.getBBox();
    let x = e.clientX - bBox.width / 2;
    let y = e.clientY - bBox.height / 2;
    elem.style.left = x + "px";
    elem.style.top = y + "px";
}

function Init(aWindow, ScriptURL, callBack) {

    console.log("Initializing...");
    gWindow = aWindow;
    gDoc = gWindow.document;
    //gWindow = aWindow;
    scriptParentURL = ScriptURL.substring(0, ScriptURL.lastIndexOf("/"));


    let fIncRec = function (fCallBack) {
        let tA = window.document.querySelector("a.cInclude");

        if (tA != null) {
            let srcURL = tA.getAttribute("href");
            console.log("loading", srcURL, "...");
            let xmlHttp = new XMLHttpRequest();
            xmlHttp.open("GET", srcURL, true);
            xmlHttp.send();

            xmlHttp.onreadystatechange = (e) => {
                if (xmlHttp.readyState == 4) {
                    if (xmlHttp.status == 200) {
                        let parser = new DOMParser();
                        let dom_t = parser.parseFromString(xmlHttp.responseText, "application/xhtml+xml");
                        if (dom_t !== null) {
                            let hBody = dom_t.querySelectorAll("body >*");
                            for (let i = 0; i < hBody.length; i++) {
                                tA.parentElement.insertBefore(hBody[i], tA);
                            }
                        }
                    }
                    tA.parentElement.removeChild(tA);
                    fIncRec(fCallBack);
                    console.log(srcURL, xmlHttp.status);
                }
            }

        }
        else {
            console.log("recursive callback of inclusion ends");
            console.log("initializing documents...");
            fCallBack();
        }
    };


    fIncRec(function () {

        //Preprocessing. process all link objects
                (function () {
                    try {
                        let strCookie = localStorage.getItem("akechi_data");
                        console.log(22, strCookie)
                        let obj = JSON.parse(strCookie);
                        gidCurEvent = obj["gidCurEvent"];
                        is_laser_pointer = obj["is_laser_pointer"];
                        console.log(gidCurEvent)

                    }
                    catch (e) {
                        gidCurEvent = gDoc.querySelector("slide").id;
                        is_laser_pointer = true;
                        is_CMD = false;
                        is_Hidden = true;
                    }

                }());

                Array.prototype.forEach.call(gDoc.querySelectorAll("dmath, .cLatex"), function (e_dmath) {
                    if (e_dmath.classList.contains("cAlign")) {
                        e_dmath.insertBefore(gDoc.createTextNode("\\begin{align}"), e_dmath.firstChild);
                        e_dmath.appendChild(gDoc.createTextNode("\\end{align}"));
                    }
                    else {
                        e_dmath.insertBefore(gDoc.createTextNode("\\["), e_dmath.firstChild);
                        e_dmath.appendChild(gDoc.createTextNode("\\]"));
                    }
                }
                );
                Array.prototype.forEach.call(gDoc.querySelectorAll("imath"), function (e_imath) {
                    e_imath.insertBefore(gDoc.createTextNode("\\("), e_imath.firstChild);
                    e_imath.appendChild(gDoc.createTextNode("\\)"));
                    let parent = e_imath.parentNode;
                    parent.insertBefore(gDoc.createTextNode(" "), e_imath);
                    parent.insertBefore(gDoc.createTextNode(" "), e_imath.nextSibling);
                }
                );
                //parse sections.
                (function () {
                    let oTime = gDoc.querySelector("body > slide > time");
                    if (oTime == null) {
                        alert("there is no body > time element in this gDoc");
                    }
                    let fTime = gDoc.querySelector("body > footer > time");
                    if (fTime == null) {
                        alert("you have to set a footer > time in a gDoc");
                        throw "error: 1";
                    }

                    fTime.textContent = oTime.textContent;

                    let oCite = gDoc.querySelector("body > header > cite");
                    if(oCite == null){
                        return;
                    }
                    let recSection = function (oSection, oFooter) {
                        let l_oHeader = oSection.queryChildren(" > header");
                        (function () {
                            let l_tFooter = oSection.queryChildren(" > footer");
                            if (l_tFooter.length != 0) {
                                oFooter = l_tFooter[0];
                            }
                            if (oFooter == null) {
                                alert("you have to set at least one footer in a section");
                                oSection.textContent = "Error in this section";
                                throw "error: 1";
                            }
                        }());
                        if (l_oHeader.length == 0) {
                            alert("you have to set a header in a section");
                            oSection.textContent = "Error in this section";
                            throw "error: 1";
                        }
                        let oHeader = l_oHeader[0]

                        let loSection = oSection.queryChildren(" > section");
                        for (let i = 0; i < loSection.length; ++i) {
                            let toSection = loSection[i];
                            recSection(toSection, oFooter.cloneNode(true));
                        }
                        let t_oHeader;
                        let t_oFooter;
                        let loParagraph = oSection.queryChildren(" > slide");
                        for (let i = 0; i < loParagraph.length; ++i) {
                            //compose a slide block using the slide, header, and footer in the section to which this slide belongs.
                            oParagraph = loParagraph[i];
                            if (i != loParagraph.length - 1) {
                                t_oHeader = oHeader.cloneNode(true);
                                t_oFooter = oFooter.cloneNode(true);
                            } else {
                                t_oHeader = oHeader;
                                t_oFooter = oFooter;
                            }
                            if (oSection.tagName.toLowerCase() != "body") {
                                let oSpan1 = gDoc.createElement("span");
                                while (t_oHeader.childNodes.length != 0) {
                                    oSpan1.appendChild(t_oHeader.childNodes[0]);
                                }
                                t_oHeader.appendChild(oSpan1);
                                if (oCite != null) {
                                    t_oHeader.appendChild(oCite.cloneNode(true));
                                }
                            }
                            oParagraph.insertBefore(t_oHeader, oParagraph.firstChild);

                            if (oSection.tagName.toLowerCase() != "body") {
                                let tTime = t_oFooter.querySelector("time");
                                tTime.textContent = oTime.textContent;
                                oParagraph.appendChild(t_oFooter);
                            }
                        }

                    };

                    //body is the top section.
                    recSection(gDoc.querySelector("body"), null);
                    oCite.parentElement.removeChild(oCite);

                }());

                //add slide numbers.
                let loSlideNumber = gDoc.querySelectorAll(".cSlideNumber");
                for (let i = 0; i < loSlideNumber.length; ++i) {
                    loSlideNumber[i].textContent = i.toString() + "/" + (loSlideNumber.length - 1).toString();
                }

                let lParagraph = gDoc.getElementsByTagName("slide");

                //assign ids to articles.
                let oEvent = lParagraph[0];
                let oParagraphO = lParagraph[0];
                for (let cp = 0; cp < lParagraph.length; cp++) {
                    oParagraph = lParagraph[cp];

                    let id = "i_Paragraph_" + cp.toString();
                    oParagraph.setAttribute("id", id);

                    let loAnchor = oParagraph.querySelectorAll("a");
                    for (let i = 0; i < loAnchor.length; ++i) {
                        let oAnchor = loAnchor[i];
                        oAnchor.onclick = function (event) {
                            event.stopPropagation();
                        };
                    }
                    oParagraph.setAttribute("data-xPreviousEventID", oParagraphO.id);
                    oEvent.setAttribute("data-xNextEventID", oParagraph.id);
                    oEvent = oParagraph;

                    let loFigures = oParagraph.querySelectorAll("figure");
                    for (let i = 0; i < loFigures.length; ++i) {
                        let oFigure = loFigures[i];
                        let loVideos = oFigure.querySelectorAll("video");

                        if (loVideos.length !== 0) {
                            oFigure.setAttribute("id", "i_figure" + cp.toString() + "_" + i.toString());
                            oFigure.setAttribute("data-xPreviousEventID", oParagraph.id);
                            oFigure.setAttribute("data-xParagraphID", oParagraph.id);
                            oEvent.setAttribute("data-xNextEventID", oFigure.id);
                            oEvent = oFigure;
                        }
                    }
                    oParagraph.setAttribute("data-xParagraphID", oParagraph.id);

                    oParagraphO = oParagraph;
                }

                oEvent.setAttribute("data-xNextEventID", oEvent.id);


                oEvent = gDoc.getElementById(gidCurEvent);
                if (oEvent == null) {
                    gidCurEvent = gDoc.querySelector("slide").id;
                }

                // add event handlers after assigning ID and initializing gidCurEvent, to reduce null pointer from gidCurEvent.
                for (let cp = 0; cp < lParagraph.length; cp++) {
                    oParagraph = lParagraph[cp];

                    oParagraph.onclick = function () {
                        let oEvent = gDoc.getElementById(gidCurEvent);
                        let pid = oEvent.getAttribute("data-xParagraphID");

                        if (pid == this.id) {
                            nextEvent();
                        }
                        else {
                            gidCurEvent = this.id
                            setPage();
                        }
                    };
                }

                /****************create a menu for a debug usage************************/

                gDoc.addEventListener('webkitfullscreenchange', exitHandler, false);
                gDoc.addEventListener('fullscreenchange', exitHandler, false);
                gDoc.addEventListener('MSFullscreenChange', exitHandler, false);

                enableLaserPointer();
                setScales(100);

                gWindow.onmousemove = function (e) {
                    pointerMove(e);
                };

                gWindow.onbeforeunload = function () {
                    let t_json = JSON.stringify({
                        "gidCurEvent": gidCurEvent, "is_laser_pointer": is_laser_pointer
                    });
                    localStorage.setItem("akechi_data", t_json);
                };


                gWindow.addEventListener("keydown", function (e) {
                    if (function () {
                        if (e.which === 70) {
                            let elem = gDoc.documentElement;

                            if (function () {
                                if (elem.requestFullscreen) {
                                    elem.requestFullscreen();
                                }
                                else if (elem.mozRequestFullScreen) { /* Firefox */
                                    elem.mozRequestFullScreen();
                                }
                                else if (elem.webkitRequestFullscreen) { /* Chrome, Safari and Opera */
                                    elem.webkitRequestFullscreen();
                                }
                                else if (elem.msRequestFullscreen) { /* IE/Edge */
                                    elem.msRequestFullscreen();
                                }
                                else {
                                    return false;
                                }
                                return true;
                            }()) {
                                setScales(250);
                            }
                            return true;
                        }
                        else if (e.which === 112) { //F1
                            //show menu pannel;
                            is_CMD = !is_CMD;
                            setScales(100);
                            return true;
                        }
                        else if (e.which === 76)//L
                        {
                            //laser pointer
                            is_laser_pointer = !is_laser_pointer;
                            enableLaserPointer();
                            return true;
                        }
                        else if (e.which === 80)//P
                        {
                            //laser pointer
                            change_to_printingMode();
                            return true;
                        }
                        else if (function () {
                            if (e.which === 73) {
                                nextEvent();
                                return true;
                            }
                            if (e.which === 34 || e.which === 39 || e.which === 13) {
                                nextEvent();
                                return true;
                            }
                            else if (e.which === 33 || e.which === 37) {
                                previousEvent();
                                return true;
                            }
                            else {
                                return false;
                            }
                        }()) {

                            return true;
                        }
                        return false;
                    }()) {
                        e.preventDefault();
                    }

                }, false);


                gWindow.location.href = "#";
                callBack();
            
        
    });
};
