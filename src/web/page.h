const char Starting_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>SuperSmartClock</title>
</head>
<body> 
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Fira+Sans:wght@400&display=swap');
*{
    font-family: 'Fira Sans', sans-serif;
    margin: 0;
}
/*--------------------- SWITCH ----------------- */
switch__static{
    display: flex;
    justify-content: center;
}
.switch__static--posicion{
    display: flex;
    margin: 20px auto;
    width: max-content;
    align-items: center;
}
.switch__static label{
    cursor: pointer;
    position: relative;
    width: 56px;
    height: 28px;
    border-radius: 20px;
    background: #D7D5D3;
    transition: 0.3s;
}
.switch__static input{
    display: none;
}
.switch__static .circle::after{
    position: absolute;
    cursor: pointer;
    margin-top: 4px;
    margin-left: 5px;
    content: "";
    width: 20px;
    height: 20px;
    border-radius: 20px;
    background-color: #fff;
    box-shadow: 0px 2px 8px rgba(0, 0, 0, 0.2);
    transition: 0.3s;
}
input:checked + label .circle::after {
    margin-left: 32px;
    transition: 0.3s;
}
input:checked + label{
    /* background: #65C466; */
    transition: 0.3s;
    background-color: #007AFF;
}
.switch__static__name{
    font-style: normal;
    font-weight: normal;
    font-size: 20px;
    line-height: 30px;
    text-align: center;
    color: #32344B;
    margin: 0 30px 0;
}




.title{
    margin: 40px auto 40px;
    width: 100%;
    text-align: center;
    font-style: normal;
    font-weight: normal;
    font-size: 25px;
    line-height: 30px;
}
.netwok__title{
    text-align: center;
    font-size: 30px;
}
/* ---------BUTTTON------------*/
.btn{
    margin:50px auto 20px;
    text-align: center;
}
.btn button{
    padding: 0 45px 0 ;
    cursor: pointer;
    width: max-content;
    height: 40px;
    left: 661px;
    top: 604px;
    font-size: 16px;
    line-height: 18px;
    color: #fff;
    border: none;
    background: #007AFF;
    border-radius: 30px;
}
.form{

    justify-content: center;
}

/*--------- MessageBOX --------*/

.message__box{
    left: 50%;
    transform: translate(-50%);
    bottom: 70px;
    position: absolute;
    padding: 10px 0 10px;
    text-align: center;
    width: 400px;
    background-color: rgba(20, 173, 20, 0.623);
    border-radius: 10px;
    color: #fff;
    box-shadow: 0px 0.5px 4px rgba(0, 0, 0, 0.25);
    transition: 0.7s;
}
.message__box span{
    font-size: 24px;
}
/*--------- ADDRES IP INPUTE --------*/

.static__address__ip{
    overflow: hidden;
    margin: auto;
    width: max-content;
}
.static__address__ip--title{
    margin-left: 10px;
    margin-bottom: 5px;
}
.static__address__ip--title:first-of-type {
    margin-top: 30px;
}
.static__address__ip .form__static__addres__container{
    margin-bottom: 30px;
}

.static__address__ip--open{
    max-height: 500px;
    transition: max-height 0.7s ease-in;
}
.static__address__ip--close{
    max-height: 0;
    transition: max-height 0.7s ease-out;
}
/*--------- INPUTE TEXT --------*/

.form__input__constaner{
    position: relative;
    caret-color: #007AFF;
    width: 325px;
    height: 50px;
    border: 2px solid #32344B;
    box-sizing: border-box;
    border-radius: 6px;
    margin: 50px auto;
}
.form__input__constaner .form__input__constaner--input{
    margin: 18px 10px;
    width: 300px;
    height: 24px;
    z-index: 1000;
    font-style: normal;
    font-weight: normal;
    font-size: 16px;
    line-height: 150%;
    color: #595959;
    border: none;
}
.form__input__constaner--description{
    margin-left: 10px;
    font-size: 13px;
    color: #C4C4C4;
}
.form__input__constaner .active{
    margin-left: 12px;
    position: absolute;
    margin-top: 4px;
    font-style: normal;
    font-weight: normal;
    font-size: 12px;
    transition: 0.1s;
    color: #C4C4C4;

}
.form__input__constaner .close{
    position: absolute;
    margin-left: 16px;
    margin-top: 12px;
    font-style: normal;
    font-weight: normal;
    font-size: 16px;
    line-height: 150%;
    color: #595959;
    transition: 0.1s;
}


.form__static__addres__container{
    display: inline-flex;
    align-items: center;
    margin: auto;
}
.form__static__addres__container input{
    font-style: normal;
    font-weight: normal;
    font-size: 16px;
    line-height: 21px;
    color: #595959;
    width: 55px;
    text-align: center;
    height: 38px;
    margin-right: 5px;
    margin-left: 5px;
    border: 2px solid #32344B;
    box-sizing: border-box;
    border-radius: 6px;
}

input, label{
    display: block;
}
input:focus{
    outline: none;
}
.cursorTransparent{
    caret-color: transparent;
}
    </style>
    <div class="message__box" hidden>
        <span>OK !!!</span>
        <p>An attempt was made to connect to the network</p>
    </div>
    <div class="title">
        <svg width="209" height="31" viewBox="0 0 209 31" fill="none" xmlns="http://www.w3.org/2000/svg">
            <path d="M40.975 24.2C40.1083 24.2 39.2 24.1667 38.25 24.1C37.3167 24.05 36.5 23.9667 35.8 23.85V22.15C37.5667 22.3333 39.0917 22.425 40.375 22.425C41.175 22.425 41.8 22.3833 42.25 22.3C42.7167 22.2167 43.1 22.0667 43.4 21.85C43.7 21.65 43.8917 21.35 43.975 20.95C44.0583 20.5333 44.1 19.975 44.1 19.275C44.1 18.3917 44.0583 17.775 43.975 17.425C43.8917 17.075 43.7 16.825 43.4 16.675C43.1167 16.525 42.6 16.4 41.85 16.3L38.325 15.85C37.475 15.7333 36.8333 15.4917 36.4 15.125C35.9833 14.7583 35.7083 14.2833 35.575 13.7C35.4417 13.1167 35.375 12.35 35.375 11.4C35.375 10.1167 35.575 9.13333 35.975 8.45C36.375 7.75 36.9583 7.26667 37.725 7C38.5083 6.73333 39.5333 6.6 40.8 6.6C41.6667 6.6 42.5083 6.64167 43.325 6.725C44.1583 6.79167 44.8417 6.88333 45.375 7V8.65C44.1417 8.46667 42.7667 8.375 41.25 8.375C40.4 8.375 39.725 8.425 39.225 8.525C38.725 8.625 38.3417 8.78333 38.075 9C37.7917 9.21667 37.6 9.50833 37.5 9.875C37.4167 10.225 37.375 10.7167 37.375 11.35C37.375 12.0833 37.4167 12.6167 37.5 12.95C37.5833 13.2833 37.75 13.525 38 13.675C38.25 13.8083 38.6583 13.9083 39.225 13.975L42.675 14.425C43.575 14.5417 44.2583 14.725 44.725 14.975C45.2083 15.2083 45.5667 15.6417 45.8 16.275C46.0167 16.8083 46.125 17.7417 46.125 19.075C46.125 20.4917 45.9333 21.575 45.55 22.325C45.1667 23.0583 44.6083 23.5583 43.875 23.825C43.1583 24.075 42.1917 24.2 40.975 24.2ZM57.051 22.2H56.901C56.651 22.85 56.2426 23.35 55.676 23.7C55.1093 24.0333 54.2843 24.2 53.201 24.2C52.1176 24.2 51.301 24.0333 50.751 23.7C50.201 23.3667 49.826 22.8583 49.626 22.175C49.4426 21.4917 49.351 20.5333 49.351 19.3V11.25H51.251V18.6C51.251 19.8 51.3176 20.6583 51.451 21.175C51.5843 21.6917 51.826 22.0333 52.176 22.2C52.5426 22.3667 53.1426 22.45 53.976 22.45C54.8926 22.45 55.5593 22.2833 55.976 21.95C56.3926 21.6 56.651 21.125 56.751 20.525C56.8676 19.9083 56.926 19.025 56.926 17.875V11.25H58.826V24H57.126L57.051 22.2ZM62.6084 11.25H64.3084L64.4084 13.05H64.5334C64.8167 12.2667 65.2751 11.7417 65.9084 11.475C66.5417 11.1917 67.3084 11.05 68.2084 11.05C69.3417 11.05 70.2001 11.2417 70.7834 11.625C71.3667 11.9917 71.7751 12.6333 72.0084 13.55C72.2584 14.4667 72.3834 15.8167 72.3834 17.6C72.3834 19.3833 72.2667 20.7417 72.0334 21.675C71.8001 22.5917 71.3917 23.2417 70.8084 23.625C70.2251 24.0083 69.3667 24.2 68.2334 24.2C67.2834 24.2 66.5167 24.0667 65.9334 23.8C65.3501 23.5167 64.9251 23.05 64.6584 22.4H64.5084V28.9H62.6084V11.25ZM67.4834 22.475C68.4167 22.475 69.0751 22.3667 69.4584 22.15C69.8584 21.9333 70.1251 21.5083 70.2584 20.875C70.4084 20.225 70.4834 19.1417 70.4834 17.625C70.4834 16.1083 70.4084 15.0333 70.2584 14.4C70.1251 13.75 69.8584 13.3167 69.4584 13.1C69.0751 12.8833 68.4167 12.775 67.4834 12.775C66.7334 12.775 66.1417 12.9 65.7084 13.15C65.2751 13.3833 64.9751 13.775 64.8084 14.325C64.6751 14.7083 64.5917 15.15 64.5584 15.65C64.5251 16.15 64.5084 16.8083 64.5084 17.625C64.5084 19.1083 64.5917 20.1417 64.7584 20.725C64.9417 21.3583 65.2501 21.8083 65.6834 22.075C66.1167 22.3417 66.7167 22.475 67.4834 22.475ZM84.7943 18.275H77.1443C77.1443 19.575 77.211 20.5083 77.3443 21.075C77.4943 21.6417 77.811 22.0333 78.2943 22.25C78.7943 22.4667 79.611 22.575 80.7443 22.575C81.811 22.575 83.0193 22.4833 84.3693 22.3V23.85C83.9193 23.95 83.311 24.0333 82.5443 24.1C81.7943 24.1667 81.061 24.2 80.3443 24.2C78.811 24.2 77.686 24.0083 76.9693 23.625C76.2527 23.225 75.7777 22.5833 75.5443 21.7C75.3277 20.8167 75.2193 19.4667 75.2193 17.65C75.2193 15.85 75.3193 14.5167 75.5193 13.65C75.7193 12.7667 76.1693 12.1167 76.8693 11.7C77.586 11.2667 78.711 11.05 80.2443 11.05C81.6777 11.05 82.711 11.2583 83.3443 11.675C83.9777 12.075 84.3777 12.7083 84.5443 13.575C84.711 14.425 84.7943 15.775 84.7943 17.625V18.275ZM80.1943 12.675C79.2443 12.675 78.561 12.775 78.1443 12.975C77.7443 13.175 77.4777 13.5583 77.3443 14.125C77.211 14.675 77.1443 15.5833 77.1443 16.85H82.9693V16.6C82.9693 15.4167 82.886 14.5583 82.7193 14.025C82.5693 13.475 82.3027 13.1167 81.9193 12.95C81.5527 12.7667 80.9777 12.675 80.1943 12.675ZM88.0967 11.25H89.7967L89.8967 13.675H90.0467C90.2967 12.675 90.73 11.9917 91.3467 11.625C91.98 11.2417 92.805 11.05 93.8217 11.05V12.975C92.8217 12.975 92.0383 13.1583 91.4717 13.525C90.9217 13.875 90.5383 14.4167 90.3217 15.15C90.105 15.8667 89.9967 16.825 89.9967 18.025V24H88.0967V11.25ZM101.375 24.2C100.509 24.2 99.6004 24.1667 98.6504 24.1C97.7171 24.05 96.9004 23.9667 96.2004 23.85V22.15C97.9671 22.3333 99.4921 22.425 100.775 22.425C101.575 22.425 102.2 22.3833 102.65 22.3C103.117 22.2167 103.5 22.0667 103.8 21.85C104.1 21.65 104.292 21.35 104.375 20.95C104.459 20.5333 104.5 19.975 104.5 19.275C104.5 18.3917 104.459 17.775 104.375 17.425C104.292 17.075 104.1 16.825 103.8 16.675C103.517 16.525 103 16.4 102.25 16.3L98.7254 15.85C97.8754 15.7333 97.2337 15.4917 96.8004 15.125C96.3837 14.7583 96.1087 14.2833 95.9754 13.7C95.8421 13.1167 95.7754 12.35 95.7754 11.4C95.7754 10.1167 95.9754 9.13333 96.3754 8.45C96.7754 7.75 97.3587 7.26667 98.1254 7C98.9087 6.73333 99.9337 6.6 101.2 6.6C102.067 6.6 102.909 6.64167 103.725 6.725C104.559 6.79167 105.242 6.88333 105.775 7V8.65C104.542 8.46667 103.167 8.375 101.65 8.375C100.8 8.375 100.125 8.425 99.6254 8.525C99.1254 8.625 98.7421 8.78333 98.4754 9C98.1921 9.21667 98.0004 9.50833 97.9004 9.875C97.8171 10.225 97.7754 10.7167 97.7754 11.35C97.7754 12.0833 97.8171 12.6167 97.9004 12.95C97.9837 13.2833 98.1504 13.525 98.4004 13.675C98.6504 13.8083 99.0587 13.9083 99.6254 13.975L103.075 14.425C103.975 14.5417 104.659 14.725 105.125 14.975C105.609 15.2083 105.967 15.6417 106.2 16.275C106.417 16.8083 106.525 17.7417 106.525 19.075C106.525 20.4917 106.334 21.575 105.95 22.325C105.567 23.0583 105.009 23.5583 104.275 23.825C103.559 24.075 102.592 24.2 101.375 24.2ZM123.826 16.65C123.826 15.4333 123.768 14.575 123.651 14.075C123.551 13.5583 123.343 13.2167 123.026 13.05C122.71 12.8833 122.176 12.8 121.426 12.8C120.576 12.8 119.96 12.9667 119.576 13.3C119.193 13.6167 118.951 14.075 118.851 14.675C118.751 15.275 118.701 16.175 118.701 17.375V24H116.801V16.65C116.801 15.4333 116.743 14.575 116.626 14.075C116.526 13.5583 116.318 13.2167 116.001 13.05C115.685 12.8833 115.151 12.8 114.401 12.8C113.568 12.8 112.951 12.975 112.551 13.325C112.168 13.6583 111.926 14.1333 111.826 14.75C111.726 15.35 111.676 16.225 111.676 17.375V24H109.776V11.25H111.476L111.576 13.05H111.701C111.935 12.4167 112.318 11.925 112.851 11.575C113.385 11.225 114.16 11.05 115.176 11.05C116.193 11.05 116.951 11.2083 117.451 11.525C117.951 11.825 118.293 12.3333 118.476 13.05H118.626C118.86 12.4167 119.251 11.925 119.801 11.575C120.368 11.225 121.16 11.05 122.176 11.05C123.176 11.05 123.926 11.2167 124.426 11.55C124.926 11.8833 125.268 12.3917 125.451 13.075C125.635 13.7583 125.726 14.7083 125.726 15.925V24H123.826V16.65ZM132.504 24.2C131.17 24.2 130.212 23.9333 129.629 23.4C129.045 22.85 128.754 21.875 128.754 20.475C128.754 19.5083 128.854 18.7583 129.054 18.225C129.27 17.675 129.629 17.2833 130.129 17.05C130.645 16.8 131.362 16.675 132.279 16.675C132.745 16.675 134.104 16.7167 136.354 16.8V15.95C136.354 14.9167 136.27 14.1833 136.104 13.75C135.937 13.3 135.629 13.0167 135.179 12.9C134.745 12.7667 134.004 12.7 132.954 12.7C132.487 12.7 131.895 12.725 131.179 12.775C130.479 12.825 129.912 12.8833 129.479 12.95V11.4C130.645 11.1667 132.004 11.05 133.554 11.05C134.887 11.05 135.879 11.2 136.529 11.5C137.195 11.7833 137.645 12.2667 137.879 12.95C138.129 13.6333 138.254 14.6333 138.254 15.95V24H136.554L136.454 22.225H136.329C136.029 23.025 135.537 23.5583 134.854 23.825C134.187 24.075 133.404 24.2 132.504 24.2ZM133.179 22.55C133.879 22.55 134.445 22.4833 134.879 22.35C135.329 22.2 135.662 21.9083 135.879 21.475C136.195 20.825 136.354 19.95 136.354 18.85V18.125H132.779C132.162 18.125 131.704 18.1833 131.404 18.3C131.12 18.4 130.92 18.6083 130.804 18.925C130.687 19.225 130.629 19.7 130.629 20.35C130.629 20.9833 130.695 21.45 130.829 21.75C130.962 22.05 131.204 22.2583 131.554 22.375C131.904 22.4917 132.445 22.55 133.179 22.55ZM141.979 11.25H143.679L143.779 13.675H143.929C144.179 12.675 144.612 11.9917 145.229 11.625C145.862 11.2417 146.687 11.05 147.704 11.05V12.975C146.704 12.975 145.92 13.1583 145.354 13.525C144.804 13.875 144.42 14.4167 144.204 15.15C143.987 15.8667 143.879 16.825 143.879 18.025V24H141.979V11.25ZM151.204 24V12.9H148.979V11.25H151.204V7.55H153.104V11.25H155.729V12.9H153.104V24H151.204ZM167.464 23.875C167.014 23.975 166.464 24.05 165.814 24.1C165.181 24.1667 164.572 24.2 163.989 24.2C162.189 24.2 160.881 23.9833 160.064 23.55C159.247 23.1 158.697 22.2833 158.414 21.1C158.131 19.9 157.989 18 157.989 15.4C157.989 12.8167 158.131 10.9333 158.414 9.75C158.697 8.55 159.247 7.725 160.064 7.275C160.897 6.825 162.206 6.6 163.989 6.6C164.572 6.6 165.181 6.63333 165.814 6.7C166.464 6.76667 166.989 6.85 167.389 6.95V8.6C166.422 8.45 165.447 8.375 164.464 8.375C163.014 8.375 161.997 8.51667 161.414 8.8C160.831 9.08333 160.447 9.68333 160.264 10.6C160.081 11.5167 159.989 13.1167 159.989 15.4C159.989 17.6833 160.081 19.2833 160.264 20.2C160.447 21.1167 160.831 21.7167 161.414 22C161.997 22.2833 163.014 22.425 164.464 22.425C165.647 22.425 166.647 22.35 167.464 22.2V23.875ZM170.494 24V5.425H172.394V24H170.494ZM180.658 24.2C179.092 24.2 177.967 24.025 177.283 23.675C176.6 23.3083 176.158 22.7 175.958 21.85C175.775 20.9833 175.683 19.575 175.683 17.625C175.683 15.675 175.775 14.275 175.958 13.425C176.158 12.5583 176.6 11.95 177.283 11.6C177.967 11.2333 179.092 11.05 180.658 11.05C182.225 11.05 183.35 11.2333 184.033 11.6C184.717 11.95 185.15 12.5583 185.333 13.425C185.533 14.275 185.633 15.675 185.633 17.625C185.633 19.575 185.533 20.9833 185.333 21.85C185.15 22.7 184.717 23.3083 184.033 23.675C183.35 24.025 182.225 24.2 180.658 24.2ZM180.658 22.55C181.692 22.55 182.408 22.4417 182.808 22.225C183.225 21.9917 183.483 21.575 183.583 20.975C183.683 20.3583 183.733 19.2417 183.733 17.625C183.733 16.0083 183.683 14.9 183.583 14.3C183.483 13.6833 183.225 13.2667 182.808 13.05C182.408 12.8167 181.692 12.7 180.658 12.7C179.625 12.7 178.908 12.8167 178.508 13.05C178.108 13.2667 177.858 13.6833 177.758 14.3C177.658 14.9 177.608 16.0083 177.608 17.625C177.608 19.2583 177.658 20.375 177.758 20.975C177.858 21.575 178.108 21.9917 178.508 22.225C178.908 22.4417 179.625 22.55 180.658 22.55ZM196.152 23.875C195.752 23.9583 195.261 24.0333 194.677 24.1C194.111 24.1667 193.577 24.2 193.077 24.2C191.677 24.2 190.644 23.9833 189.977 23.55C189.327 23.1 188.902 22.4333 188.702 21.55C188.519 20.6667 188.427 19.3583 188.427 17.625C188.427 15.8917 188.544 14.575 188.777 13.675C189.011 12.7583 189.452 12.0917 190.102 11.675C190.752 11.2583 191.719 11.05 193.002 11.05C193.519 11.05 194.061 11.0833 194.627 11.15C195.194 11.2167 195.669 11.2917 196.052 11.375V12.95C195.219 12.7833 194.352 12.7 193.452 12.7C192.519 12.7 191.836 12.825 191.402 13.075C190.986 13.325 190.702 13.7833 190.552 14.45C190.419 15.1167 190.352 16.175 190.352 17.625C190.352 19.1083 190.427 20.1833 190.577 20.85C190.727 21.5 191.011 21.95 191.427 22.2C191.861 22.4333 192.552 22.55 193.502 22.55C194.402 22.55 195.286 22.4667 196.152 22.3V23.875ZM206.259 24L202.434 18.4H200.959V24H199.059V5.425H200.959V16.725H202.434L206.259 11.25H208.334L203.984 17.425L208.409 24H206.259Z" fill="black"/>
            <path d="M2.58334 12.9167C10.3333 4.30512 20.6667 4.30512 28.4167 12.9167" stroke="#2B38C5" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"/>
            <path d="M7.75 18.0833C12.4 12.9167 18.6 12.9167 23.25 18.0833" stroke="#2B38C5" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"/>
            <path d="M15.5 24.5416C16.2134 24.5416 16.7917 23.9633 16.7917 23.25C16.7917 22.5366 16.2134 21.9583 15.5 21.9583C14.7866 21.9583 14.2083 22.5366 14.2083 23.25C14.2083 23.9633 14.7866 24.5416 15.5 24.5416Z" stroke="#2B38C5" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"/>
        </svg>            
    </div>  
    <div class="netwok__title">
        <span>Enter Network name</span>
    </div>
    <div class="form">
        <div class="form__input__constaner network__name">
            <label class="form__input__constaner--label close">Network name</label>
            <input class="form__input__constaner--input" type="text" maxlength="64" name="networkName" id="networkName">
            <div class="form__input__constaner--description"><span>Max 64 characters.</span></div>
        </div>
        <div class="form__input__constaner network__pass">
            <label class="form__input__constaner--label close">Password</label>
            <input class="form__input__constaner--input" type="password" maxlength="64" name="networkPass" id="networkPass">
            <div class="form__input__constaner--description"><span>Max 64 characters.</span></div>
        </div>

        <div class="switch__static">
            <div class="switch__static--posicion">
                <div>
                    <input type="checkbox" name="networkStaticIPSwitch" id="networkStaticIPSwitch">
                    <label for="networkStaticIPSwitch">
                        <span class="circle"></span>
                    </label>
                </div>
                <div class="switch__static__name">
                    <span>Static address</span>
                </div>
            </div>
        </div>

        <div class="static__address__ip static__address__ip--close" id="networkStaticIP">
            <div class="static__address__ip--title">
                <span>IP address</span>
            </div>
            <div class="form__static__addres__container">
                <input value="0"  type="text" name="networkIP0" id="networkIP0" maxlength="3">
                <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/>
                    </svg>
                    
                <input value="0"  type="text" name="networkIP1" id="networkIP1" maxlength="3">
                <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/>
                    </svg>
                    
                <input value="0" type="text" name="networkIP2" id="networkIP2" maxlength="3">
                <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/>
                    </svg>
                    
                <input value="0"  type="text" name="networkIP3" id="networkIP3" maxlength="3">
            </div>

            <div class="static__address__ip--title">
                <span>Default Gateway</span>
            </div>
            <div class="form__static__addres__container">
                <input value="0"  type="text" name="networkGateway0" id="networkGateway0" maxlength="3">
                <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/>
                    </svg>
                    
                <input value="0"  type="text" name="networkGateway1" id="networkGateway1" maxlength="3">
                <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/>
                    </svg>
                    
                <input value="0" type="text" name="networkGateway2" id="networkGateway2" maxlength="3">
                <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/>
                    </svg>
                    
                <input value="0"  type="text" name="networkGateway3" id="networkGateway3" maxlength="3">
            </div>

            <div class="static__address__ip--title">
                <span>Subnetwork mask</span>
            </div>
            <div class="form__static__addres__container">
                <input value="255" type="text" name="networkMask0" id="networkMask0" maxlength="3">
                <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/>
                    </svg>
                    
                <input value="255"  type="text" name="networkMask1" id="networkMask1" maxlength="3">
                <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/>
                    </svg>
                    
                <input value="255" type="text" name="networkMask2" id="networkMask2" maxlength="3">
                <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/>
                    </svg>
                    
                <input value="0"  type="text" name="networkMask3" id="networkMask3" maxlength="3">
            </div>
        </div>

            <!-- <div class="form__static__addres">
                <div class="form__static__addres--title">
                    <span>Subnet mask</span>
                    <span></span>
                </div>
                <div class="form__static__addres__container">
                    <input value="0"  type="text" name="mask1" id="mask1" maxlength="3">
                    <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg">
                        <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/>
                        </svg>
                        
                    <input value="0"  type="text" name="mask2" id="mask2" maxlength="3">
                    <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg">
                        <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/>
                        </svg>
                        
                    <input value="0" type="text" name="mask3" id="mask3" maxlength="3">
                    <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg">
                        <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/>
                        </svg>
                        
                    <input value="0"  type="text" name="mask4" id="mask4" maxlength="3">
                </div>
            </div> -->
        </div>
        <div class="btn">
            <button onclick="send()">Connect</button>
        </div>
    </div>

    <script>

        const formInputConstaner = document.querySelectorAll('.form__input__constaner')
        const ssidInpute = document.querySelectorAll('.form__input__constaner--input')
        const ssidLabel = document.querySelectorAll('.form__input__constaner--label')

        for (let i = 0; i < formInputConstaner.length; i++) {
                
            formInputConstaner[i].addEventListener('click', () => {
                ssidInpute[i].focus()
                ssidLabel[i].classList.remove("close")
                ssidLabel[i].classList.add("active")
                ssidInpute[i].classList.remove("cursorTransparent")
            })

            ssidInpute[i].addEventListener('focusout', ()  => {
                if(ssidInpute[i].value == ""){
                    ssidLabel[i].classList.add("close")
                    ssidLabel[i].classList.remove("active")
                    ssidInpute[i].classList.add("cursorTransparent")
                }
            })
                
            ssidInpute[i].addEventListener('input', () => {
                if(ssidInpute[i].value == ""){
                    ssidLabel[i].classList.add("close")
                    ssidLabel[i].classList.remove("active")
                    ssidInpute[i].classList.add("cursorTransparent")
                }else{
                    ssidLabel[i].classList.remove("close")
                    ssidLabel[i].classList.add("active")
                    ssidInpute[i].classList.remove("cursorTransparent")
                }

            })
        }

        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        const networkStaticIPSwitch = document.querySelector('#networkStaticIPSwitch')
        const networkStaticIP = document.querySelector('#networkStaticIP')

        networkStaticIPSwitch.addEventListener('input', () => {
            networkStaticIP.classList.toggle('static__address__ip--open')
            networkStaticIP.classList.toggle('static__address__ip--close')
        })
        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        const send = () => {
            const ssid = document.querySelector('input[name="networkName"]').value
            const pass = document.querySelector('input[name="networkPass"]').value
            const address = ipInputeToArray('networkIP')
            const gateway = ipInputeToArray('networkGateway')
            const mask = ipInputeToArray('networkMask')
            const data = {
                name: ssid,
                staticIpEnable: networkStaticIPSwitch.checked,
                pass: pass,
                address: address,
                gateway: gateway,
                mask: mask
            }
            console.log(data)
            postData('/setNetworkConfig', data)
            .then(data => {
                if(data == "OK"){
                    document.querySelector('.message__box').hidden = false
                    setTimeout(() => {
                        document.querySelector('.message__box').hidden = true
                    }, 4000);
                }
            });
        }

        const ipInputeToArray = (objectID) => {
            let array = [0, 0, 0, 0];
            for (let i = 0; i < 4; i++) {
                const object = document.querySelector("#" + objectID + i).value
                console.log(object)
                array[i] = object
            }
            return array
        }
        
        async function postData(url = '', data = {}) {
            const response = await fetch(url, {
                method: 'POST',
                mode: 'cors',
                cache: 'no-cache',
                credentials: 'same-origin',
                headers: {
                'Content-Type': 'application/json'
                },
                redirect: 'follow',
                referrerPolicy: 'no-referrer', 
                body: JSON.stringify(data)
            });
            return response.text();
        }
    </script>
</body>

</html>

    </script>
</body>

</html>
)=====";

const char home_page_HTML[] PROGMEM = R"=====(
<!DOCTYPE html><html lang="en"><head> <meta charset="UTF-8"> <meta http-equiv="X-UA-Compatible" content="IE=edge"> <link rel="stylesheet" href="/style"> <link href='https://unpkg.com/boxicons@2.0.9/css/boxicons.min.css' rel='stylesheet'> <meta name="viewport" content="width=device-width, initial-scale=1.0"> <title>SuperSmartClock</title></head><body> <div class="load"> <span>Loading...</span> </div><div class="message__box__error"> <div class="message__box__error__icon"> <i class='bx bx-error-circle'></i> </div><div class="message__box__error__text"> <span>Fetch error</span> </div></div><div class="message__box__ok"> <div class="message__box__ok__icon"> <i class='bx bx-check-circle'></i> </div><div class="message__box__ok__text"> <span>Successes</span> </div></div><div id="menuTab" class="menu__tabs"> <div class="logo"> <img src="https://czubixx.xyz/supersmartclock/icon/logo.svg"> </div><div class="displayScrollText"> <div class="displayScrollText--title"> <span>Display Scrolling Text</span> </div><div class="form__input__constaner"> <label class="form__input__constaner--label close">Text</label> <input class="form__input__constaner--input" type="text" name="sendText" id="sendText"> <div class="form__input__constaner--description"><span>Max 128 characters.</span></div></div><div class="range__container"> <label for="repetitions">Speed: </label> <input type="range" min="50" max="70" value="60" name="range" id="repetitions"><br></div><div class="displayScrollText__send"> <button onclick="displayScrollTestHandling()">Wyślij</button> </div></div></div><div id="menuTab" class="menu__tabs"> <div class="alarm__filtr" id="alarmFiltr" onclick="hideAlarmEdit()" hidden></div><div class="logo"> <img src="https://czubixx.xyz/supersmartclock/icon/logo.svg"> </div><div class="alarm__conatainer" > <div id="alarma__box__constainer"> <div class="alarm__box--none"> <div> <span>No alarm</span> <p>click “+” to add a new alarm</p></div></div></div></div><div class="alarm__btnadd"> <div class="alarm__btnadd--icon" id="alarmAddBtn"> <i class='bx bx-plus'></i> </div></div><div class="alarm__add" id="alarmAddCard" hidden> <div class="alarm__add__content"> <div class="alarm__add__time"> <div class="alarm__add__time--hours"> <input value="12" min="0" max="23" type="number" name="alarmAddHours" id="alarmAddHours"> </div><div> <span> : </span> </div><div class="alarm__add__time--min"> <input value="00" min="0" max="59" type="number" name="alarmAddMin" id="alarmAddMin"> </div></div><div class="alarm__add__day"> <div class="alarm__add__day--input"> <input type="checkbox" id="alarmAddDayMON" name="alarmAddDay"> <div class="case"> <label for="alarmAddDayMON">Mon</label> </div></div><div class="alarm__add__day--input"> <input type="checkbox" id="alarmAddDayTue" name="alarmAddDay"> <div class="case"> <label for="alarmAddDayTue">Tue</label> </div></div><div class="alarm__add__day--input"> <input type="checkbox" id="alarmAddDayWed" name="alarmAddDay"> <div class="case"> <label for="alarmAddDayWed">Wed</label> </div></div><div class="alarm__add__day--input"> <input type="checkbox" id="alarmAddDayThu" name="alarmAddDay"> <div class="case"> <label for="alarmAddDayThu">Thu</label> </div></div><div class="alarm__add__day--input"> <input type="checkbox" id="alarmAddDayFri" name="alarmAddDay"> <div class="case"> <label for="alarmAddDayFri">Fri</label> </div></div><div class="alarm__add__day--input"> <input type="checkbox" id="alarmAddDaySat" name="alarmAddDay"> <div class="case"> <label for="alarmAddDaySat">Sat</label> </div></div><div class="alarm__add__day--input"> <input type="checkbox" id="alarmAddDaySun" name="alarmAddDay"> <div class="case"> <label for="alarmAddDaySun">Sun</label> </div></div></div><div class="form__input__constaner alarm__add__name"> <label class="form__input__constaner--label close">Alarm name</label> <input class="form__input__constaner--input" type="text" name="alarmAddName" id="alarmAddName"> <div class="form__input__constaner--description"> <span>Max 64 characters.</span> </div></div><div class="btn alarm__add--btn"> <button onclick="alarmAddHandler()">Add alarm</button> </div></div></div></div></div><div id="menuTab" class="menu__tabs"> <div class="logo"> <img src="https://czubixx.xyz/supersmartclock/icon/logo.svg"> </div><div class="box"> <div class="box__card"> <div class="box__card__content"> <div class="box__card__content--icon"> <svg width="30" height="30" viewBox="0 0 30 30" fill="none" xmlns="http://www.w3.org/2000/svg"> <path d="M7.4925 15C7.4925 19.1415 10.8615 22.5105 15.003 22.5105C19.1445 22.5105 22.5135 19.1415 22.5135 15C22.5135 10.8585 19.1445 7.4895 15.003 7.4895C10.8615 7.4895 7.4925 10.8585 7.4925 15ZM15.003 10.4895C17.49 10.4895 19.5135 12.513 19.5135 15C19.5135 17.487 17.49 19.5105 15.003 19.5105C12.516 19.5105 10.4925 17.487 10.4925 15C10.4925 12.513 12.516 10.4895 15.003 10.4895ZM13.5 25.5H16.5V30H13.5V25.5ZM13.5 0H16.5V4.5H13.5V0ZM0 13.5H4.5V16.5H0V13.5ZM25.5 13.5H30V16.5H25.5V13.5ZM3.3315 24.5445L6.5115 21.3615L8.634 23.4825L5.454 26.6655L3.3315 24.5445ZM21.363 6.516L24.546 3.333L26.667 5.454L23.484 8.637L21.363 6.516ZM6.516 8.6385L3.333 5.4555L5.4555 3.3345L8.6355 6.5175L6.516 8.6385ZM26.667 24.546L24.546 26.667L21.363 23.484L23.484 21.363L26.667 24.546Z" fill="black"/> </svg> </div><div class="box__card__content--name"> <span class="title">Brightness</span><br><span class="description">Display brightness settings</span> </div><div class="box__card__content--arrow"> <img src="https://czubixx.xyz/supersmartclock/icon/arrow.svg"> </div></div></div><div class="box__content" style="height: 0px;"> <div class="selector__two"> <div class="selector__two__input"> <input type="radio" name="brightness" class="brightness--auto" id="brightness--auto" value="auto" > <label for="brightness--auto"><span>Auto</span></label> </div><div class="selector__two--line"><span></span></div><div class="selector__two__input"> <input type="radio" name="brightness" class="brightness--manual" id="brightness--manual" value="manual" checked> <label for="brightness--manual"><span>Manual</span></label> </div></div><div class="brightness__slider "> <div class="range__value" id="range__value"></div><input type="range" min="0" max="15" value="10" name="range" id="brightness"><br></div><div class="btn brightness__saveButton"> <button onclick="brightnessHandling()">Save</button> </div></div></div><div class="box"> <div class="box__card"> <div class="box__card__content"> <div class="box__card__content--icon"> <i class='bx bx-moon' style="font-size: 36px;"></i> </div><div class="box__card__content--name"> <span class="title">Night mode</span><br><span class="description">Configuration of the night mode</span> </div><div class="box__card__content--arrow"> <img src="https://czubixx.xyz/supersmartclock/icon/arrow.svg"> </div></div></div><div class="box__content" style="height: 0px;"> <div class="night__mode__box__container"> <div class="switch__static night__mode__switch"> <div class="switch__static--posicion"> <div> <input type="checkbox" name="nightModeSwitch" id="nightModeSwitch"> <label for="nightModeSwitch" class="switch__static__label"> <span class="circle"></span> </label> </div><div class="switch__static__name"> <span>Night mode</span> </div></div></div><div class="night__mode__box__time"> <div class="night__mode__box__container__time"> <div class="night__mode__box__container__time__title"> <span>from</span> </div><div class="night__mode__box__container__time__picker"> <input type="number" value="22" name="nightModeFromHours" id="nightModeFromHours"> <span>:</span><input type="number" value="59" name="nightModeFromMin" id="nightModeFromMin"> </div></div><div class="night__mode__box__container__time"> <div class="night__mode__box__container__time__title"> <span>to</span> </div><div class="night__mode__box__container__time__picker"> <input type="number" value="22" name="nightModeToHours" id="nightModeToHours"> <span>:</span><input type="number" value="59" name="nightModetoMin" id="nightModetoMin"> </div></div></div><div class="btn night__mode__save"> <button onclick="nightModeHandling()">Save</button> </div></div></div></div><div class="box"> <div class="box__card"> <div class="box__card__content"> <div class="box__card__content--icon"> <svg width="30" height="30" viewBox="0 0 30 30" fill="none" xmlns="http://www.w3.org/2000/svg"> <path d="M15 0C6.729 0 0 6.729 0 15C0 23.271 6.729 30 15 30C23.271 30 30 23.271 30 15C30 6.729 23.271 0 15 0ZM15 27C8.3835 27 3 21.6165 3 15C3 8.3835 8.3835 3 15 3C21.6165 3 27 8.3835 27 15C27 21.6165 21.6165 27 15 27Z" fill="black"/> <path d="M15.9743 8H13V15.4616L17.8972 20L20 18.0512L15.9743 14.3204V8Z" fill="black"/> </svg> </div><div class="box__card__content--name"> <span class="title">Time Zone</span><br><span class="description">Configuring time zone settings</span> </div><div class="box__card__content--arrow"> <img src="https://czubixx.xyz/supersmartclock/icon/arrow.svg"> </div></div></div><div class="box__content" style="height: 0px;"> <div class="form__input__constaner timeZone"> <label class="form__input__constaner--label close">NTP Server IP</label> <input class="form__input__constaner--input" type="text" name="timeZone" id="timeZone"> <div class="form__input__constaner--description"><span>Max 32 characters.</span></div></div><div class="form__TimeZone"> <div class="form__TimeZone--minus"> <button id="timeUTPZone--minus"> <svg width="22" height="2" viewBox="0 0 22 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line x1="12" y1="1" x2="22" y2="1" stroke="#32344B" stroke-width="2"/> <line x1="1.74846e-07" y1="1" x2="10" y2="1" stroke="#32344B" stroke-width="2"/> <rect x="10" width="2" height="2" fill="#32344B"/> </svg> </button> </div><div class="form__TimeZone--input"> <input type="text" value="+0 h" name="timeUTPZone" id="timeUTPZone" disabled> </div><div class="form__TimeZone--plus"> <button id="timeUTPZone--plus"> <svg width="22" height="22" viewBox="0 0 22 22" fill="none" xmlns="http://www.w3.org/2000/svg"> <line x1="11" x2="11" y2="10" stroke="#32344B" stroke-width="2"/> <line x1="11" y1="12" x2="11" y2="22" stroke="#32344B" stroke-width="2"/> <line x1="12" y1="11" x2="22" y2="11" stroke="#32344B" stroke-width="2"/> <line x1="1.74846e-07" y1="11" x2="10" y2="11" stroke="#32344B" stroke-width="2"/> <rect x="10" y="10" width="2" height="2" fill="#32344B"/> </svg> </button> </div></div><div class="timeZone__message"> <div class="timeZone__message--icon"> <i class='bx bx-info-circle'></i> </div><div class="timeZone__message--text"> <span> NTP servers allow you to display the time, you can get the NTP server IP address for your time location from <a href="https://gist.github.com/mutin-sa/eea1c396b1e610a2da1e5550d94b0453" target="_blank">github.com</a> </span> </div></div><div class="btn timeZone--btn"> <button onclick="timeZoneHandling()">Save and Reboot</button> </div></div></div><div class="box"> <div class="box__card"> <div class="box__card__content"> <div class="box__card__content--icon"> <i class='bx bxs-thermometer' style="font-size: 30px;" ></i> </div><div class="box__card__content--name"> <span class="title">Temperature</span><br><span class="description">Configuring mqtt settings</span> </div><div class="box__card__content--arrow"> <img src="https://czubixx.xyz/supersmartclock/icon/arrow.svg"> </div></div></div><div class="box__content" style="height: 0px;"> <div class="selector__two"> <div class="selector__two__input"> <input type="radio" name="tempUnit" id="tempUnitC" value="c" > <label for="tempUnitC"><span>Celsius</span></label> </div><div class="selector__two--line"><span></span></div><div class="selector__two__input"> <input type="radio" name="tempUnit" id="tempUnitF" value="f"> <label for="tempUnitF"><span>Fahrenheit</span></label> </div></div><div class="temperature__shunter"> <div class="temperature__shunter--minus"> <button id="tempMinus"> <svg width="22" height="2" viewBox="0 0 22 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line x1="12" y1="1" x2="22" y2="1" stroke="#32344B" stroke-width="2"/> <line x1="1.74846e-07" y1="1" x2="10" y2="1" stroke="#32344B" stroke-width="2"/> <rect x="10" width="2" height="2" fill="#32344B"/> </svg> </button> </div><div class="temperature__shunter--input"> <input type="text" value="+0" name="temperature" id="temperature" disabled> </div><div class="temperature__shunter--plus"> <button id="tempPlus"> <svg width="22" height="22" viewBox="0 0 22 22" fill="none" xmlns="http://www.w3.org/2000/svg"> <line x1="11" x2="11" y2="10" stroke="#32344B" stroke-width="2"/> <line x1="11" y1="12" x2="11" y2="22" stroke="#32344B" stroke-width="2"/> <line x1="12" y1="11" x2="22" y2="11" stroke="#32344B" stroke-width="2"/> <line x1="1.74846e-07" y1="11" x2="10" y2="11" stroke="#32344B" stroke-width="2"/> <rect x="10" y="10" width="2" height="2" fill="#32344B"/> </svg> </button> </div></div><div class="btn temperature--btn"> <button onclick="temepratureHandling()">Save</button> </div></div></div><div class="box"> <div class="box__card"> <div class="box__card__content"> <div class="box__card__content--icon"> <i class='bx bx-sun' style="font-size: 32px;"></i> </div><div class="box__card__content--name"> <span class="title">Weather</span><br><span class="description">Outdoor temperature configuration</span> </div><div class="box__card__content--arrow"> <img src="https://czubixx.xyz/supersmartclock/icon/arrow.svg"> </div></div></div><div class="box__content box__weather" style="height: 0px;"> <div class="selector__two"> <div class="selector__two__input"> <input type="radio" name="weatherUnit" id="weatherUnitC" value="c"> <label for="weatherUnitC"><span>Celsius</span></label> </div><div class="selector__two--line"><span></span></div><div class="selector__two__input"> <input type="radio" name="weatherUnit" id="weatherUnitF" value="f"> <label for="weatherUnitF"><span>Fahrenheit</span></label> </div></div><div class="form__input__constaner box__weather--api"> <label class="form__input__constaner--label close">API key</label> <input class="form__input__constaner--input" type="text" name="weatherKey" id="weatherKey"> <div class="form__input__constaner--description"><span>Max 32 characters.</span></div></div><div class="form__input__constaner box__weather--api"> <label class="form__input__constaner--label close">City Name</label> <input class="form__input__constaner--input" type="text" name="weatherCity" id="weatherCity"> <div class="form__input__constaner--description"><span>Max 64 characters.</span></div></div><div class="timeZone__message"> <div class="timeZone__message--icon"> <i class='bx bx-info-circle'></i> </div><div class="weather__message--text"> <span> See how to get the api key on the site <a href="https://openweathermap.org/appid" target="_blank">openweathermap.org</a><br>Check if your town is supported <a href="https://openweathermap.org/find?q=" target="_blank">openweathermap.org</a> </span> </div></div><div class="btn temperature--btn"> <button onclick="weatherHandling()">Save and Reboot</button> </div></div></div><div class="box"> <div class="box__card"> <div class="box__card__content"> <div class="box__card__content--icon"> <i class='bx bx-cloud-upload' style="font-size: 32px;"></i> </div><div class="box__card__content--name"> <span class="title">Updates</span><br><span class="description">Update management</span> </div><div class="box__card__content--arrow"> <img src="https://czubixx.xyz/supersmartclock/icon/arrow.svg"> </div></div></div><div class="box__content" style="height: 0px;"> <div class="update__firmware__info"> <div class="update__firmware__info--icon"> <i class='bx bx-copy-alt'></i> </div><div class="update__firmware__info--description"> <span>Firmware version: </span><span id="firmwareVersion">v1.b</span> </div></div><div class="firmware__drop__section" id="filedropsection"> <input class="firmware__drop__section__input" type="file" name="fffff" id="fffff"> <div class="firmware__drop__section__content"> <div class="firmware__drop__section__content__watermark"> <div class="firmware__drop__section__content__file__icon"> <img src="https://czubixx.xyz/supersmartclock/icon/upload_file.svg"> </div><div class="firmware__drop__section__content__text"> <span id="firmwareDropMessage">Upload or drag and drop the .bin file</span> </div></div><div class="firmware__drop__btn"> <button id="checkUpdateBtn" onclick="firmwareHandlerSend()">Update</button> </div></div></div></div></div><div class="box"> <div class="box__card"> <div class="box__card__content"> <div class="box__card__content--icon"> <i class='bx bx-wifi' style="font-size: 32px;"></i> </div><div class="box__card__content--name"> <span class="title">Network</span><br><span class="description">Network settings</span> </div><div class="box__card__content--arrow"> <img src="https://czubixx.xyz/supersmartclock/icon/arrow.svg"> </div></div></div><div class="box__content" style="height: 0px;"> <div class="form__input__constaner network__name"> <label class="form__input__constaner--label close">Network name</label> <input class="form__input__constaner--input" type="text" maxlength="64" name="networkName" id="networkName"> <div class="form__input__constaner--description"><span>Max 64 characters.</span></div></div><div class="form__input__constaner network__pass"> <label class="form__input__constaner--label close">Password</label> <input class="form__input__constaner--input" type="password" maxlength="64" name="networkPass" id="networkPass"> <div class="form__input__constaner--description"><span>Max 64 characters.</span></div></div><div class="switch__static"> <div class="switch__static--posicion"> <div> <input type="checkbox" name="networkStaticIPSwitch" id="networkStaticIPSwitch"> <label for="networkStaticIPSwitch" class="switch__static__label"> <span class="circle"></span> </label> </div><div class="switch__static__name"> <span>Static address</span> </div></div></div><div class="static__address__ip static__address__ip--close" id="networkStaticIP"> <div class="static__address__ip--title"> <span>IP address</span> </div><div class="form__static__addres__container"> <input value="0" type="text" name="networkIP0" id="networkIP0" maxlength="3"> <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/> </svg> <input value="0" type="text" name="networkIP1" id="networkIP1" maxlength="3"> <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/> </svg> <input value="0" type="text" name="networkIP2" id="networkIP2" maxlength="3"> <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/> </svg> <input value="0" type="text" name="networkIP3" id="networkIP3" maxlength="3"> </div><div class="static__address__ip--title"> <span>Default Gateway</span> </div><div class="form__static__addres__container"> <input value="0" type="text" name="networkGateway0" id="networkGateway0" maxlength="3"> <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/> </svg> <input value="0" type="text" name="networkGateway1" id="networkGateway1" maxlength="3"> <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/> </svg> <input value="0" type="text" name="networkGateway2" id="networkGateway2" maxlength="3"> <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/> </svg> <input value="0" type="text" name="networkGateway3" id="networkGateway3" maxlength="3"> </div><div class="static__address__ip--title"> <span>Subnetwork mask</span> </div><div class="form__static__addres__container"> <input value="255" type="text" name="networkMask0" id="networkMask0" maxlength="3"> <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/> </svg> <input value="255" type="text" name="networkMask1" id="networkMask1" maxlength="3"> <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/> </svg> <input value="255" type="text" name="networkMask2" id="networkMask2" maxlength="3"> <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/> </svg> <input value="0" type="text" name="networkMask3" id="networkMask3" maxlength="3"> </div><div class="static__address__ip__message"> <div class="static__address__ip__message--icon"> <i class='bx bx-info-circle'></i> </div><div class="static__address__ip__message--text"> <span> if the ip address is wrong, the device may not catch the errors </span> </div></div></div><div class="btn network__btn__save"> <button onclick="networkHandler()">Save and Reboot</button> </div></div></div><div class="box"> <div class="box__card"> <div class="box__card__content"> <div class="box__card__content--icon"> <i class='bx bx-station' style="font-size: 30px;" ></i> </div><div class="box__card__content--name"> <span class="title">MQTT</span><br><span class="description">Configuring mqtt settings</span> </div><div class="box__card__content--arrow"> <img src="https://czubixx.xyz/supersmartclock/icon/arrow.svg"> </div></div></div><div class="box__content mqtt__box" style="height: 0px;"> <div class="switch__static mqtt__switch"> <div class="switch__static--posicion"> <div> <input type="checkbox" name="mqtt__switch" id="mqtt__switch"> <label for="mqtt__switch" class="switch__static__label"> <span class="circle"></span> </label> </div><div class="switch__static__name"> <span>Enable MQTT</span> </div></div></div><div class="form__input__constaner mqtt_user"> <label class="form__input__constaner--label close">Name</label> <input class="form__input__constaner--input" type="text" name="MqqttUser" id="MqqttUser"> <div class="form__input__constaner--description"><span>Max 32 characters.</span></div></div><div class="form__input__constaner mqtt_pass"> <label class="form__input__constaner--label close">Password</label> <input class="form__input__constaner--input" type="password" name="MqqttPass" id="MqqttPass"> <div class="form__input__constaner--description"><span>Max 32 characters.</span></div></div><div class="mqqtt__static__IP"> <div class="mqqtt__static__IP--title"> <span>Broker IP</span> </div><div class="form__static__addres__container"> <input value="0" type="text" name="mqttip1" id="mqttip1" maxlength="3"> <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/> </svg> <input value="0" type="text" name="mqttip2" id="mqttip2" maxlength="3"> <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/> </svg> <input value="0" type="text" name="mqttip3" id="mqttip3" maxlength="3"> <svg width="16" height="2" viewBox="0 0 16 2" fill="none" xmlns="http://www.w3.org/2000/svg"> <line y1="1" x2="16" y2="1" stroke="#32344B" stroke-width="2"/> </svg> <input value="0" type="text" name="mqttip4" id="mqttip4" maxlength="3"> </div></div><div class="form__input__constaner mqtt_topic"> <label class="form__input__constaner--label close">Mqtt device topic</label> <input class="form__input__constaner--input" type="text" name="mqttTopic" id="mqttTopic"> <div class="form__input__constaner--description"><span>Max 32 characters.</span></div></div><div class="mqtt__message"> <div class="mqtt__message--icon"> <i class='bx bx-info-circle'></i> </div><div class="mqtt__message--text"> <span> See the addresses to which the request should be sent and the full Mqtt documentation on <a href="https://gist.github.com/mutin-sa/eea1c396b1e610a2da1e5550d94b0453" target="_blank">github.com</a> </span> </div></div><div class="mqqtt__button"> <button onclick="mqttHandling()">Save and Reboot</button> </div></div></div></div><div class="menu__category"> <div id="menuButton" class="menu__category__text menu__tab__open" onclick="openTabs(0)"> <div class="menu__category__text--icon"> <i class='bx bx-text'></i> </div><div class="menu__category__text--text"> <span>Display text</span> </div></div><div id="menuButton" class="menu__category__settings" onclick="openTabs(1)"> <div class="menu__category__settings--icon"> <i class='bx bx-alarm'></i> </div><div class="menu__category__settings--text"> <span>Alarm</span> </div></div><div id="menuButton" class="menu__category__settings" onclick="openTabs(2)"> <div class="menu__category__settings--icon"> <i class='bx bx-cog'></i> </div><div class="menu__category__settings--text"> <span>Settings</span> </div></div></div><script src="/app"></script></body></html>
)=====";

const char home_page_CSS[] PROGMEM = R"=====(
/* @import url('//db.onlinewebfonts.com/c/0a086e32e41c5e5960b26626757f07f3?family=Apercu'); */@import url('https://fonts.googleapis.com/css2?family=Fira+Sans:wght@400&display=swap');*{font-family: 'Fira Sans', sans-serif; margin: 0;}label,input{display: block; outline: none;}.cursorTransparent{caret-color: transparent;}.btn{margin:0 auto 20px; text-align: center;}.btn button{padding: 0 45px 0 ; cursor: pointer; width: max-content; height: 40px; left: 661px; top: 604px; font-size: 16px; line-height: 18px; color: #fff; border: none; background: #007AFF; border-radius: 30px;}/*--------------------------------- Load--------------------- */.load{width: 100%; height: 100%; position: fixed; background-color: #fff; z-index: 1000; transition: 0.3s;}.load span{font-size: 25px; position: absolute; left: 50%; top: 50%; transform: translate(-50%, -50%);}/*--------------------------------- Logo & tilte--------------------- */.logo{width: 100%; display: block; text-align: center; margin:60px auto 100px;}.tilte{width: 100%; display: block; text-align: center; margin:40px auto 40px;}/* ---------------------------------- Message Box ----------------------------------------------------*/.message__box__error{z-index: 9; position: absolute; overflow: hidden; bottom: 130px; margin-left: auto; margin-right: auto; left: 0; right: 0; width: 244px; height: 53px; background: #FF8C8C; border-radius: 10px; display: inline-flex; align-items: center; box-shadow: 0px 0.5px 7px rgba(255, 0, 0, 0.40); opacity: 0; transform: translateY(100px); visibility: hidden; transition: 0.5s ease-out;}.message__box__error__icon{font-size: 30px; width: 35%; text-align: center;}.message__box__error__icon i{margin-top: 5px; color: #E13232;}.message__box__error__text{text-align: left; margin-left: 30px; color: #E13232; width: 90%;}.message__box__error--open{opacity: 1; visibility: visible; transform: translateY(0px);}.message__box__ok{z-index: 9; position: absolute; overflow: hidden; bottom: 130px; margin-left: auto; margin-right: auto; left: 0; right: 0; width: 244px; height: 53px; background: #64CC7B; border-radius: 10px; display: inline-flex; align-items: center; box-shadow: 0px 0.5px 7px rgba(0, 255, 0, 0.40); opacity: 0; transform: translateY(100px); visibility: hidden; transition: 0.5s ease-out;}.message__box__ok__icon{font-size: 30px; width: 35%; text-align: center;}.message__box__ok__icon i{margin-top: 5px; color: #246942;}.message__box__ok__text{text-align: left; margin-left: 30px; color: #246942; width: 90%;}.message__box__ok--open{opacity: 1; visibility: visible; transform: translateY(0px);}/* ---------------------------------- menu tabs ----------------------------------------------------*/.menu__tabs--open{display: block;}.menu__tabs{overflow-y: scroll; overflow-x: hidden; height: calc(100vh - 68px);}.menu__tabs--close{display: none;}.menu__tabs::-webkit-scrollbar{width: 10px;}/* Track */ .menu__tabs::-webkit-scrollbar-track{background: #f1f1f1;}/* Handle */ .menu__tabs::-webkit-scrollbar-thumb{background: #888; border-radius: 10px;}/* Handle on hover */ .menu__tabs::-webkit-scrollbar-thumb:hover{background: #555;}/* ----------------------------------Two options selector------------------------------------ */.selector__two{width: 300px; height: 42px; background-color: #EDEDED; margin: 10px auto; border-radius: 16px; display: flex;}.selector__two__input{width: 140px; position: relative;}.selector__two--line{width: 20px; height: 42px; position: relative;}.selector__two--line span{display: block; left: 50%; top: 50%; width: 2px; height: 22px; position: absolute; background-color: #fff; transform: translate(-50%,-50%);}.selector__two__input input{display: none;}.selector__two__input label{position: relative; margin: 6px auto; width: 114px; cursor: pointer; text-align: center; height: 30px;}.selector__two__input label span{position: absolute; top: 47%; left: 0; right: 0; bottom: 0; margin: auto; transform: translate(0, -50%); transition: 0.3s;}.selector__two__input input:checked + label{background-color: #fff; transition: 0.3s; box-shadow: 0px 0.5px 4px rgba(0, 0, 0, 0.25); border-radius: 10px;}/*--------- INPUTE TEXT --------*/.form__input__constaner{position: relative; caret-color: #007AFF; width: 325px; height: 50px; border: 2px solid #32344B; box-sizing: border-box; border-radius: 6px; margin: 50px auto;}.form__input__constaner .form__input__constaner--input{margin: 18px 10px; width: 300px; height: 24px; z-index: 1000; font-style: normal; font-weight: normal; font-size: 16px; line-height: 150%; color: #595959; border: none;}.form__input__constaner--description{margin-left: 10px; font-size: 13px; color: #C4C4C4;}.form__input__constaner .active{margin-left: 12px; position: absolute; margin-top: 4px; font-style: normal; font-weight: normal; font-size: 12px; transition: 0.1s; color: #C4C4C4;}.form__input__constaner .close{position: absolute; margin-left: 16px; margin-top: 12px; font-style: normal; font-weight: normal; font-size: 16px; line-height: 150%; color: #595959; transition: 0.1s;}/*--------------------- SWITCH ----------------- */switch__static{display: flex; justify-content: center;}.switch__static--posicion{display: flex; margin: 20px auto; width: max-content; align-items: center;}.switch__static label{cursor: pointer; position: relative; width: 56px; height: 28px; border-radius: 20px; background: #D7D5D3; transition: 0.3s;}.switch__static input{display: none;}.switch__static .circle::after{position: absolute; cursor: pointer; margin-top: 4px; margin-left: 5px; content: ""; width: 20px; height: 20px; border-radius: 20px; background-color: #fff; box-shadow: 0px 2px 8px rgba(0, 0, 0, 0.2); transition: 0.3s;}input:checked + .switch__static__label .circle::after{margin-left: 32px; transition: 0.3s;}input:checked + .switch__static__label{/* background: #65C466; */ transition: 0.3s; background-color: #007AFF;}.switch__static__name{font-style: normal; font-weight: normal; font-size: 20px; line-height: 30px; text-align: center; color: #32344B; margin: 0 30px 0;}/* --------------RANGE CONSTAINER-------------- */.range__container{width: 300px; margin:80px auto; height: max-content; position: relative;}.range__container label{margin-bottom: 20px;}.range__container input{width: 100%; background: linear-gradient(to right, #007AFF 0%, #007AFF 0%, #D8D8D9 0%, #D8D8D9 100%); border-radius: 8px; height: 7px; outline: none; transition: background 450ms ease-in; -webkit-appearance: none;}.range__container input::-webkit-slider-thumb{appearance: none; width: 25px; height: 25px; top: -50%; border-radius: 50%; cursor: ew-resize; background: #FFFFFF; box-shadow: 0px 0.5px 4px rgba(0, 0, 0, 0.12), 0px 6px 13px rgba(0, 0, 0, 0.12);}.range__container input::-moz-range-thumb{appearance: none; width: 25px; height: 25px; border: none; top: -50%; border-radius: 50%; cursor: ew-resize; background: #FFFFFF; box-shadow: 0px 0.5px 4px rgba(0, 0, 0, 0.12), 0px 6px 13px rgba(0, 0, 0, 0.12);}/* --------------------Button Send-------------- */.displayScrollText__send{margin:0 auto 100px; text-align: center;}.displayScrollText__send button{cursor: pointer; width: 131px; height: 40px; left: 661px; top: 604px; font-size: 16px; line-height: 18px; color: #fff; border: none; background: #007AFF; border-radius: 30px;}/* ---------------------------------- Display scroling Text ----------------------------------------------------*/.displayScrollText{margin-top: 30px;}.displayScrollText--title{font-size: 30px; text-align: center;}/* ----------------------------------------------------------ALARM----------------------------------------------- */.alarm__conatainer{width: 100%; height: max-content;}.alarm__box{width: 432px; overflow: hidden; height: 132px; margin: 50px auto; background: #FFFFFF; box-shadow: 0px 0.5px 4px rgba(0, 0, 0, 0.25); border-radius: 12px; cursor: s-resize; transition: 0.3s ease-in-out;}.alarm__box--slideOut{transform: translateX(-100%); opacity: 0; transition: 1s ease-in-out;}.alarm__box__constent__posicion{margin-top: 14px; margin-bottom: 14px; display: flex; width: 432px; align-items: center;}.alarm__box__content{width: 50%; padding: 0px 40px 0; box-sizing: content-box; align-items: center;}.alarm__box__switch{width: 30%; align-items: center;}.alarm__box__content--day{display: flex; align-items: center; margin-bottom: 10px;}.alarm__box__content--day .icon{font-size: 10px; margin-bottom: 2px; display: flex;}.alarm__box__content--day .content{margin-left: 6px; font-size: 15px; display: flex;}.alarm__box__content--time{font-size: 40px; margin-bottom: 8px;}.alarm__box__content--name{font-size: 17px;}.alarm__btnadd{position: fixed; bottom: 120px; width: 100%; transition: 0.3s;}.alarm__btnadd--icon{position: relative; width: 68px; height: 68px; margin: 0 auto; background: #007AFF; box-shadow: 0px 0.5px 4px #007AFF; border-radius: 50px; transition: 0.3s;}.alarm__btnadd--icon i{position: absolute; top: 50%; left: 50%; transform: translate(-50%,-50%); font-size: 35px; color: #fff; transition: 0.3s;}.alarm__btnadd--icon:hover{opacity: 0.9; cursor: pointer; transition: 0.3s;}@media screen and (max-width: 480px){.alarm__box{width: 330px; height: 122px; margin: 25px auto; background: #FFFFFF; box-shadow: 0px 0.5px 4px rgba(0, 0, 0, 0.25); border-radius: 12px; align-items: center;}.alarm__box__constent__posicion{margin-top: 14px; margin-bottom: 14px; display: flex; width: 330px; align-items: center;}.alarm__box__content--time{font-size: 33px; margin-bottom: 8px;}.alarm__box__content--name{font-size: 15px;}.alarm__box__content--day .content{margin-left: 6px; font-size: 12px; display: flex;}.alarm__box__content{width: 50%; padding: 0px 30px 0; box-sizing: content-box;}}/* -----------------Alarm box none---------- */.alarm__box--none{margin: 20vh auto; align-items: center; /* height: calc(50vh); */ display: flex; justify-content: center; align-items: center; width: 100%;}.alarm__box--none div{text-align: center; margin: auto; width: max-content;}.alarm__box--none div span{font-size: 40px;}.alarm__box--none div p{color: #717171;}/*---------------------Alarm delete---------------*/.alarm__box__action{margin-top: 20px; width: 100%; padding: 0 40px 0;}.alarm__box__action--btn{float: left;}.alarm__box--open{height: 200px; transition: 0.3s;}@media screen and (max-width: 480px){.alarm__box__action{margin-top: 30px; padding: 0 20px 0;}}/*--------------- ALARM add card--------------- */.alarm__add{position: fixed; z-index: 100; border-radius: 25px; background-color: white; bottom: 0; width: 100%; height: 600px; overflow-y: auto;}.alarm__add__content{width: 100%; position: static;}/* ---------------Alarm time picker-------- */.alarm__filtr{position: absolute; z-index: 99; width: 100%; height: 100%; background: rgba(0, 0, 0, 0.15);}.alarm__add__time{display: flex; width: max-content; margin: 50px auto 30px; font-size: 50px;}.alarm__add__time--hours input{font-size: 70px; width: 90px; border: none; text-align: center; margin-right: 10px; border-bottom: 2px solid #fff;}.alarm__add__time--min input{font-size: 70px; width: 90px; border: none; margin-left: 10px; text-align: center; border-bottom: 2px solid #fff;}.alarm__add__time--min input:hover, .alarm__add__time--hours input:hover{border-bottom: 2px solid #000;}.alarm__add__time--min input:focus, .alarm__add__time--hours input:focus{border-bottom: 2px solid #000;}input::-moz-inner-spin-button,input::-moz-outer-spin-button{-moz-appearance: none; margin: 0;}input::-webkit-outer-spin-button,input::-webkit-inner-spin-button{-webkit-appearance: none; margin: 0;}input[type=number]{-moz-appearance:textfield;}/* ---------------Alarm day picker-------- */.alarm__add__day{display: flex; margin: auto; -moz-user-select:none; user-select:none; -webkit-user-select:none; -ms-user-select:none; width: max-content;}.alarm__add__day--input input{display: none;}.alarm__add__day--input{position: relative; margin-left: 10px; margin-right: 10px;}.alarm__add__day--input .case label{position: absolute; height: 100%; width: 100%; color: #A3A3A3; text-align: center; align-items: center; line-height: 58px; cursor: pointer; transition: 0.2s;}.alarm__add__day--input .case{width: 30px; height: 58px; border-bottom: 2px solid #A3A3A3; transition: 0.2s;}.alarm__add__day--input input:checked + .case{transition: 0.2s; border-bottom: 2px solid #007AFF;}.alarm__add__day--input input:checked + .case label{color: #007AFF; transition: 0.2s;}.alarm__add__name{margin-top: 80px;}.alarm__add--btn button{margin-top: 40px;}@media only screen and (min-width: 750px){/* .alarm__add{position: fixed; z-index: 100; width: 500px; border-radius: 25px; min-height: 600px; background-color: white; top: 50%; left: 50%; transform: translate(-50%, -50%);}*/ .alarm__add{position: absolute; z-index: 100; border-radius: 25px; background-color: white; bottom: 0; height: 600px; width: 500px; overflow-y: auto; top: 50%; left: 50%; transform: translate(-50%, -50%);}.alarm__add__content{width: 100%; height: 500px; position: unset;}}@media only screen and (max-height: 550px){.alarm__add{height: 100%;}.alarm__add__content{width: 100%; height: 500px; position: unset;}}.alarm__add__display{animation: moveDowntoUp 0.3s linear;}.alarm__add__hidden{animation: moveUptoDown 0.3s linear; opacity: 0;}@keyframes moveUptoDown{0%{opacity: 1;}100%{opacity: 0;}}@keyframes moveDowntoUp{0%{opacity: 0;}100%{opacity: 1;}}/* ------------------------------------------------------------box--------------------------------------------- */.box{width: 100%; height: max-content;}.box:last-child{margin: 0 auto 100px;}.box__card{width: 325px; height: 68px; margin: 20px auto 20px; background: #FFFFFF; box-shadow: 0px 0.5px 4px rgba(0, 0, 0, 0.25); border-radius: 12px;}.box__card__content{margin-top: 15px; width: 100%; margin-left: 24px; display: inline-flex; align-items: center;}.box__card__content--icon{width: 50px; height: 100%;}.box__card__content--arrow{width: max-content; margin-right: 50px; cursor: pointer; transition: 0.3s;}.box__card__content--name{width: 70%; height: 100%;}.box__card__open{transform: rotate(90deg);}.box__card__content--name .title{font-style: normal; font-weight: normal; font-size: 20px; line-height: 18px;}.box__card__content--name .description{font-style: normal; font-weight: normal; font-size: 10px; line-height: 18px;}.box__content{position: relative; display: block; width: max-content; margin: auto; overflow: hidden; transition: height 300ms cubic-bezier(0.4, 0, 0.2, 1) 0s;}.box__link{color: #007AFF; cursor: pointer; text-decoration: underline;}/* ----------------------------------Brighnes BOX------------------------------------ */.brightness__slider{width: 270px; margin:90px auto 70px; position: relative; opacity: 1; transition: opacity 0.3s;}.brightness__slider input{width: 100%; margin: auto; background: linear-gradient(to right, #007AFF 0%, #007AFF 0%, #D8D8D9 0%, #D8D8D9 100%); border-radius: 8px; height: 7px; outline: none; transition: background 450ms ease-in; -webkit-appearance: none;}.brightness__slider input::-webkit-slider-thumb{appearance: none; width: 25px; height: 25px; top: -50%; border-radius: 50%; cursor: ew-resize; background: #FFFFFF; box-shadow: 0px 0.5px 4px rgba(0, 0, 0, 0.12), 0px 6px 13px rgba(0, 0, 0, 0.12);}.brightness__slider input::-moz-range-thumb{appearance: none; width: 25px; height: 25px; border: none; top: -50%; border-radius: 50%; cursor: ew-resize; background: #FFFFFF; box-shadow: 0px 0.5px 4px rgba(0, 0, 0, 0.12), 0px 6px 13px rgba(0, 0, 0, 0.12);}.brightness__slider .range__value{position: absolute; top: -50px; margin-left: -13px; border-radius: 16px; width: 27px; height: 27px; background: #FFFFFF; box-shadow: 0px 0.5px 4px rgba(0, 0, 0, 0.25);}.brightness__slider .range__value span{position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%); box-shadow: 0 16px 10px -17px rgba(0, 0, 0, 0.5);}.brightness__slider .range__value .triangle{position: absolute; z-index: -10; top: 17px; left: 0px; content: ""; border-top: 10px solid transparent; border-left: 10px solid transparent; border-right: 10px solid #fff; transform: rotate(45deg); /* Prefixes... */ -webkit-filter: drop-shadow(0 1px 4px rgba(0, 0, 0, 0.50)); filter: drop-shadow(0 1px 4px rgba(0, 0, 0, 0.50));}.disabel{opacity: 0.5; transition: 0.3s;}/* ----------------------------------Night Mode BOX------------------------------------ */.night__mode__box__time{margin: 40px 0 0 ;}.night__mode__box__container__time{display: flex; align-items: flex-end; font-size: 17px; margin: 20px 0px; width: max-content;}.night__mode__box__container__time__title{margin-right: 10px; margin-bottom: 10px; width: 50px; text-align: right;}.night__mode__box__container__time__picker{display: flex; align-items: center; font-size: 40px;}.night__mode__box__container__time__picker span{margin: 0 5px;}.night__mode__box__container__time__picker input{width: 50px; text-align: center; font-size: 40px; border: none; border-bottom: 2px solid transparent;}.night__mode__box__container__time__picker input:focus{border-bottom: 2px solid #000;}.night__mode__save{margin: 50px auto 20px;}/* ---------------------------------------Time Zone-------------------------- */.timeZone{margin-top: 20px; width: 300px;}.timeZone .form__input__constaner--input{width: 270px;}.form__TimeZone{display: flex; margin: 20px 0 40px; justify-content: center; align-items: center;}.form__TimeZone--input{width: 90px; height: max-content;}.form__TimeZone--input input:disabled{width: 90%; margin: auto; height: 47px; font-size: 20px; text-align: center; color: #000; background-color: #fff; border: 2px solid #32344B; box-sizing: border-box; border-radius: 12px; -moz-appearance: textfield;}.form__TimeZone--input input::-webkit-outer-spin-button,.form__TimeZone--input input::-webkit-inner-spin-button{-webkit-appearance: none; margin: 0;}.form__TimeZone--plus button, .form__TimeZone--minus button{background-color: transparent; margin: 0 15px 0; border: none; cursor: pointer;}.timeZone__message{display: flex; justify-content: center;}.timeZone__message--icon{width: 40px; font-size: 26px; color: #007AFF;}.timeZone__message--text{font-size: 14px; line-height: 18px; width: 237px; height: 81px;}.timeZone__message--text a{color: #007AFF;}.timeZone--btn{margin-top: 25px;}/* ----------------------------------Temperature BOX------------------------------------ */.temperature__shunter{display: flex; margin: 60px 0 60px; justify-content: center; align-items: center;}.temperature__shunter--input{width: 90px; height: max-content;}.temperature__shunter--input input:disabled{width: 90%; margin: auto; height: 47px; font-size: 20px; text-align: center; color: #000; background-color: #fff; border: 2px solid #32344B; box-sizing: border-box; border-radius: 12px; -moz-appearance: textfield;}.temperature__unit__radio__input input, .temperature__unit__radio__input label{display: inline;}.temperature__unit{width: auto; margin: 40px auto;}.temperature__unit__text{font-size: 16px;}.temperature__unit__radio__input{margin: 10px 0; font-size: 16px;}.temperature__shunter--input input::-webkit-outer-spin-button,.temperature__shunter--input input::-webkit-inner-spin-button{-webkit-appearance: none; margin: 0;}.temperature__shunter--plus button, .temperature__shunter--minus button{background-color: transparent; margin: 0px 15px 0; border: none; cursor: pointer;}/* ----------------------------------WEATHER BOX------------------------------------ */.box__weather--api{width: 300px;}.box__weather--api .form__input__constaner--input{width: 270px;}.weather__message--text{font-size: 14px; line-height: 18px; width: 207px; height: 81px; margin-bottom: 25px;}.weather__message--text a{color: #007AFF;}/* ----------------------------------UPDATE BOX------------------------------------ */.update__firmware__info{align-items: center; display: flex; width: max-content; margin: 10px auto 10px;}.update__firmware__info span{font-style: normal; font-weight: normal; font-size: 17px; margin-top: -5px;}.update__firmware__info--icon{margin-right: 10px; font-size: 22px; color: #007AFF;}.firmware__drop__section{position: relative; width: 254px; height: 253px; margin: 50px auto; border: 3px dashed #32344B; box-sizing: border-box; border-radius: 16px; transition: all 0.1s ease-out;}.firmware__drop__section__input{position: absolute; opacity: 0; cursor: pointer; height: 180px;}.firmware__drop__section__content__file__icon{width: max-content; margin: 30px auto; pointer-events: none;}.firmware__drop__section__content__watermark{pointer-events: none;}.firmware__drop__section__content__text{width: 160px; height: 35px; font-family: Roboto; font-style: normal; font-weight: normal; font-size: 14px; line-height: 18px; text-align: center; margin: auto; color: #61637A; pointer-events: none;}.firmware__drop__btn button{display: block; margin:30px auto 10px; cursor: pointer; width: 190px; height: 39px; border: none; color: #fff; background: #007AFF; border-radius: 30px; font-style: normal; font-weight: normal; font-size: 16px; line-height: 18px;}.firmware__drop__section--over{background-color: #E2F0FF; transition: all 0.1s ease-in; border: 3px dashed #007AFF;}.firmware__drop__section--ok{border: 3px dashed #34B951; transition: all 0.1s ease-in;}.firmware__drop__section--ok button{background-color: #34B951; transition: all 0.1s ease-in;}.firmware__drop__section--error{border: 3px dashed #E94646; transition: all 0.1s ease-in;}.firmware__drop__section--error button{background-color: #E94646; transition: all 0.1s ease-in;}/* -----------------NONE FIRMWARE------------------------ */.update__firware__none{display: flex; width: 270px; margin-left: 20px; align-items: center;}.update__firware__none--icon{margin-right: 10px; color: #2F965B; font-size: 26px;}.update--btn{margin: 40px auto 20px;}/* -----------------ERRORR FIRMWARE------------------------ */.update__firware__message{margin-top: 80px; margin-bottom: 80px; display: flex; align-items: center; margin-left: 35px;}.update__firware__message__icon{margin-right: 10px; font-size: 22px;}.update__firware__message__text{width: 200px;}/* ----------------------------------NETWORK BOX------------------------------------ */.network__name, .network__pass{width: 300px;}.network__name .form__input__constaner--input, .network__pass .form__input__constaner--input, .mqtt_topic .form__input__constaner--input{width: 270px;}.static__address__ip--title{font-style: normal; font-weight: normal; font-size: 16px; line-height: 130%; color: #595959; margin-bottom: 10px; margin-left: 10px;}.static__address__ip{overflow: hidden;}.static__address__ip--title:first-of-type{margin-top: 30px;}.static__address__ip .form__static__addres__container{margin-bottom: 30px;}.network__btn__save{margin-top: 40px; margin-bottom: 50px;}.static__address__ip--open{max-height: 500px; transition: max-height 0.3s ease-in;}.static__address__ip--close{max-height: 0; transition: max-height 0.3s ease-out;}.static__address__ip__message{margin-top: 7px; display: flex; justify-content: center;}.static__address__ip__message--icon{width: 40px; font-size: 26px; color: #007AFF;}.static__address__ip__message--text{font-size: 14px; line-height: 18px; width: 237px; height: 81px;}.static__address__ip__message--text a{color: #007AFF;}/* ----------------------------------MQTT BOX------------------------------------ */.mqtt_user, .mqtt_pass, .mqtt_topic{width: 300px;}.mqtt_user .form__input__constaner--input, .mqtt_pass .form__input__constaner--input, .mqtt_topic .form__input__constaner--input{width: 270px;}.mqqtt__static__IP{margin: auto; float: none; display: table;}.mqqtt__static__IP--title{font-style: normal; font-weight: normal; font-size: 16px; line-height: 130%; color: #595959; margin-bottom: 10px; margin-left: 10px;}.form__static__addres__container{display: inline-flex; align-items: center; margin: auto;}.form__static__addres__container input{font-style: normal; font-weight: normal; font-size: 16px; line-height: 21px; color: #595959; width: 55px; text-align: center; height: 38px; margin-right: 5px; margin-left: 5px; border: 2px solid #32344B; box-sizing: border-box; border-radius: 6px;}.switch__static__addres__name{font-style: normal; font-weight: normal; font-size: 17px; display: inline-block; line-height: 150%; margin: 0 10px 0;}.mqtt__message{display: flex; justify-content: center;}.mqtt__message--icon{width: 40px; font-size: 26px; color: #007AFF;}.mqtt__message--text{font-size: 14px; line-height: 18px; width: 237px; height: 81px;}.mqtt__message--text a{color: #007AFF;}.mqqtt__button{margin: 20px auto 50px; text-align: center;}.mqqtt__button button{cursor: pointer; width: 201px; height: 40px; left: 661px; top: 604px; font-size: 16px; line-height: 18px; color: #fff; border: none; background: #007AFF; border-radius: 30px;}/*----------------------------------------------------- Devices------------------------------------- */.device--btn{margin: 40px 0;}/*----------------------------------------------------- MENU------------------------------------- */.menu__category{position: fixed; width: 100%; display: table; z-index: 50; bottom: 0; height: 70px; background: #fff; box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.10);}.menu__category__text, .menu__category__settings{width: 33%; display: table-cell; vertical-align: middle; text-align: center; vertical-align: middle; transition: 0.3s;}.menu__category__text--text, .menu__category__settings--text{font-style: normal; font-weight: normal; font-size: 20px; line-height: 18px;}.menu__category__settings--icon, .menu__category__text--icon{font-size: 30px;}.menu__category__settings:hover, .menu__category__text:hover{background-color: #E5E5E5; transition: 0.3s; cursor: pointer;}@media only screen and (max-width: 769px){.menu__category__text--text, .menu__category__settings--text{font-style: normal; font-weight: normal; font-size: 17px; line-height: 18px;}.menu__category__settings--icon, .menu__category__text--icon{font-size: 25px;}}.menu__tab__open{background-color: #E5E5E5;}
)=====";



const char home_page_JS[] PROGMEM = R"=====( 
const loading = document.querySelector('.load')

window.onload = () =>{
    const loadTime = window.performance.timing.domContentLoadedEventEnd-window.performance.timing.navigationStart; 

    const onReady = (callback) => {
        var intervalId = window.setInterval(() => { 
          if (document.getElementsByTagName('body')[0] !== undefined) {
            window.clearInterval(intervalId)
            callback.call(this)
          }
        }, 500);
      }
      
    const setVisible = (selector, visible) => {
        loading.style.opacity = visible ? '1' : '0'
        setTimeout(() => { loading.style.display = visible ? 'block' : 'none';}, 300)
    }
      
    onReady(() => {
        setVisible('#loading', false);
    });

}

const messageBoxError = document.querySelector('.message__box__error')
const messageBoxOk = document.querySelector('.message__box__ok')

const messageBox = (status) => {
    if(status == "error"){
        messageBoxError.classList.add("message__box__error--open")
        setTimeout(() => {
            messageBoxError.classList.remove("message__box__error--open")
        }, 2000);
    }else if (status == "ok") {
        messageBoxOk.classList.add("message__box__ok--open")
        setTimeout(() => {
            messageBoxOk.classList.remove("message__box__ok--open")
        }, 2000);
    }

}   

//messageBox("error")
const inputeText = () => {
    const formInputConstaner = document.querySelectorAll('.form__input__constaner'),
        ssidInpute = document.querySelectorAll('.form__input__constaner--input'),
        ssidLabel = document.querySelectorAll('.form__input__constaner--label')

        
    for (let i = 0; i < formInputConstaner.length; i++) {
        if(ssidInpute[i].value != ""){
            ssidLabel[i].classList.remove("close")
            ssidLabel[i].classList.add("active")
        }

        formInputConstaner[i].addEventListener('click', () => {
            ssidInpute[i].focus()
            ssidLabel[i].classList.remove("close")
            ssidLabel[i].classList.add("active")
            ssidInpute[i].classList.remove("cursorTransparent")
        })
    
        ssidInpute[i].addEventListener('focusout', ()  => {
            if(ssidInpute[i].value == ""){
                ssidLabel[i].classList.add("close")
                ssidLabel[i].classList.remove("active")
                ssidInpute[i].classList.add("cursorTransparent")
            }
        })
            
        ssidInpute[i].addEventListener('input', () => {
            if(ssidInpute[i].value == ""){
                ssidLabel[i].classList.add("close")
                ssidLabel[i].classList.remove("active")
                ssidInpute[i].classList.add("cursorTransparent")
            }else{
                ssidLabel[i].classList.remove("close")
                ssidLabel[i].classList.add("active")
                ssidInpute[i].classList.remove("cursorTransparent")
            }
    
        })
    }
}



// -----------Rage Update---------------

const numberRepeat = document.querySelectorAll('input[name="range"]')
const outputRepeat = document.querySelector('#range__value')

const rageUpdate = (i) => {
    const value = (numberRepeat[i].value-numberRepeat[i].min)/(numberRepeat[i].max-numberRepeat[i].min)*100
    numberRepeat[i].style.background = 'linear-gradient(to right, #007AFF 0%, #007AFF ' + value + '%, #D8D8D9 ' + value + '%, #D8D8D9 100%)'
};

setValue = ()=>{
    const newValue = Number( (numberRepeat[1].value - numberRepeat[1].min) * 100 / (numberRepeat[1].max - numberRepeat[1].min) )
    const newPosition = 10 - (newValue * 0.2);

    outputRepeat.innerHTML = `<span>${numberRepeat[1].value}</span><span class="triangle"></span>`;
    outputRepeat.style.left = `calc(${newValue}% + (${newPosition}px))`;
};

for (let i = 0; i < numberRepeat.length; i++) {

    document.addEventListener("DOMContentLoaded", rageUpdate(i), setValue());
    numberRepeat[i].addEventListener('input', () => {rageUpdate(i); setValue();});
}

// -----------Temperature---------------

const temepratureInpute = () => {
    const tempMinusbtn = document.querySelector('#tempMinus') 
    const tempPlusbtn = document.querySelector('#tempPlus') 
    const tempOutput = document.querySelector('#temperature') 



    tempMinusbtn.addEventListener('click', () => {
        if(tempOutput.value >= -10){
            tempOutput.value = (parseInt(tempOutput.value) - 1);
            if(parseInt(tempOutput.value) >= 0){
                tempOutput.value = "+" + tempOutput.value;
            }
        }
    })
    tempPlusbtn.addEventListener('click', () => {
        if(tempOutput.value <= 10){
            tempOutput.value = (parseInt(tempOutput.value) + 1);
            if(parseInt(tempOutput.value) >= 0){
                tempOutput.value = "+" + tempOutput.value;
            }
        }
    })


}


// ------------------------Time Zone----------------------

const inputZoneTime = document.querySelector('input[name="timeZone"]')
const inputUTCZoneTime = document.querySelector('input[name="timeUTPZone"]')

const timeZoneMinus = document.querySelector('#timeUTPZone--minus') 
const timeZonePlus = document.querySelector('#timeUTPZone--plus') 

const timeZoneUTCInpute = () => {

    timeZoneMinus.addEventListener('click', () => {
        const zoneValue = inputUTCZoneTime.value
        const extractNumbersFromString = zoneValue.match(/-?\d+/g).map(Number);

        console.log(extractNumbersFromString)

        if(extractNumbersFromString <= 0){
            inputUTCZoneTime.value = (extractNumbersFromString - 1) + " h";
        }else{
            inputUTCZoneTime.value = "+" + (extractNumbersFromString - 1) + " h"; 
        }
       
        
    })

    timeZonePlus.addEventListener('click', () => {
        const zoneValue = inputUTCZoneTime.value
        const extractNumbersFromString = zoneValue.match(/-?\d+/g).map(Number);

        console.log(extractNumbersFromString)

        if(extractNumbersFromString >= -1){
            inputUTCZoneTime.value = "+" + (parseInt(extractNumbersFromString) + 1) + " h";
        }else{
            inputUTCZoneTime.value = (parseInt(extractNumbersFromString) + 1) + " h"; 
        }
    })


}

// -------------------- Network BOX -----------

const networkStaticIP = document.querySelector('#networkStaticIP')
const networkStaticIPSwitch = document.querySelector('#networkStaticIPSwitch')
const networkBox = document.querySelectorAll('.box__content')
// 6
const networkStaticIPSwitchAction = () => {
    if(networkStaticIPSwitch.checked){
        networkStaticIP.classList.remove('static__address__ip--close')
        networkStaticIP.classList.add('static__address__ip--open')
        console.log(networkBox[6].scrollHeight)
        networkBox[6].style.height = '850px'
    }else{
        networkStaticIP.classList.add('static__address__ip--close')
        networkStaticIP.classList.remove('static__address__ip--open')
        networkBox[6].style.height = '430px'
    }
}


networkStaticIPSwitch.addEventListener('input', networkStaticIPSwitchAction)




const ipInputeToArray = (objectID) => {
    let array = [0, 0, 0, 0];
    for (let i = 0; i < 4; i++) {
        const object = document.querySelector("#" + objectID + i).value
        console.log(object)
        array[i] = object
    }
    return array
}

//-------------------- Menu TABS -----------

const menuButton = document.querySelectorAll("#menuButton")
const menuTab = document.querySelectorAll('#menuTab') 

const openTabs = (tab) => {
    for (let i = 0; i < menuButton.length; i++) {
        if(i == parseInt(tab)){   
            localStorage.setItem('menuTab', tab);
            openTabstorage(tab)
        }
    }
}

const openTabstorage = (tabeIndex) => {
    if(tabeIndex != null){
        setTabs(tabeIndex)

    }else{
        const tabsFromStorage = localStorage.getItem('menuTab');
        if(tabsFromStorage != null || tabsFromStorage != undefined)
            setTabs(tabsFromStorage)
        else
            setTabs(0)

    }
}

const setTabs = (tabeIndex) => {
    menuButton[tabeIndex].classList.add("menu__tab__open")
    menuTab[tabeIndex].style.display = "block"
    
    menuButton.forEach((value, i) => { 
        if(i != tabeIndex){
            menuButton[i].classList.remove("menu__tab__open")
            menuTab[i].style.display = "none"
        }
    })
}
window.addEventListener("load", openTabstorage(null))



// ----------------ALARM------------------------------

const alarmAddCards = document.querySelector('#alarmAddCard')
const alarmFiltr = document.querySelector('#alarmFiltr')
const alarmAddBtn = document.querySelector('#alarmAddBtn')
let alarmJSON
const alarmAddCloseCard = () => {
    if(!alarmFiltr.hidden){
        alarmAddCards.classList.remove("alarm__add__display")
        alarmAddCards.classList.add("alarm__add__hidden")
        alarmFiltr.hidden = true
        setTimeout(() => {
            alarmAddCards.hidden = true

        }, 300)

    }else{
        alarmAddCards.classList.remove("alarm__add__hidden")
        alarmAddCards.classList.add("alarm__add__display")
        alarmAddCards.hidden = false
        alarmFiltr.hidden = false
    }
}
alarmAddBtn.addEventListener('click', () => {
    alarmAddCloseCard()
    alarmAddSetValue()
})
alarmFiltr.addEventListener('click', alarmAddCloseCard)


const alarmAddHours = document.querySelector('input[name="alarmAddHours"]')
const alarmAddMin = document.querySelector('input[name="alarmAddMin"]')

alarmAddHours.addEventListener('input', () => {
    if(alarmAddHours.value.length > 2){
        alarmAddHours.value = 00
    }
    if(alarmAddHours.value > 23){
        alarmAddHours.value = 23
    }
    if(alarmAddHours.value < 0){
        alarmAddHours.value = 00
    } 
})
const alarmAddTimeValidation = () => {
    if(alarmAddMin.value < 10 && alarmAddMin.value.length < 2){
        alarmAddMin.value = "0" + alarmAddMin.value
    }
    if(alarmAddHours.value < 10 && alarmAddHours.value.length < 2){
        alarmAddHours.value = "0" + alarmAddHours.value
    }
}

alarmAddHours.addEventListener('focusout', alarmAddTimeValidation)
alarmAddMin.addEventListener('focusout', alarmAddTimeValidation)

alarmAddMin.addEventListener('input', () => {
    if(alarmAddMin.value.length > 2){
        alarmAddMin.value = 00
    }
    if(alarmAddMin.value > 59){
        alarmAddMin.value = 59
    }
    if(alarmAddMin.value < 0){
        alarmAddMin.value = 00
    } 

})

const alarmAddSetValue = () => {
    var actualDate = new Date();
    if(actualDate.getHours() < 10)
        alarmAddHours.value = "0" + actualDate.getHours()
    else
        alarmAddHours.value = actualDate.getHours()

    if(actualDate.getMinutes() < 10)
        alarmAddMin.value = "0" + actualDate.getMinutes() 
    else
        alarmAddMin.value = actualDate.getMinutes()
} 



const displayEditAlarm = (i) => {
    const alarmCard = document.querySelectorAll('#alarmConstainer')
    const alarmBoxAction = document.querySelectorAll('#alarmBoxAction')
    console.log(alarmCard)

    alarmCard[i].classList.toggle("alarm__box--open")
}


const displayAlarmCard = (json) => {
    const alarmNum = parseInt(json.alarmNum)
    const alarmConstainer = document.querySelector('#alarma__box__constainer')


    alarmConstainer.innerHTML = ""
    for (let i = 0; i < alarmNum; i++) {
        let state
        console.log(json.alarm[i].status)
        if(json.alarm[i].status == "1"){
            state = "checked"
        }else{
            state = ""
        }

        let days = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]

        const dfb = Array.from(json.alarm[i].day) 

        for (let j = 0; j < dfb.length; j++) {
            switch(j){
                case 0:
                    dfb[j] == "1" ? console.log() : delete days[6];
                    break;
                case 1:
                    dfb[j] == "1" ? console.log() : delete days[0];
                    break;
                case 2:
                    dfb[j] == "1" ? console.log() : delete days[1];
                    break;
                case 3:
                    dfb[j] == "1" ? console.log() : delete days[2];
                    break;
                case 4:
                    dfb[j] == "1" ? console.log() : delete days[3];
                    break;
                case 5:
                    dfb[j] == "1" ?  console.log() : delete days[4];
                    break;
                case 6:
                    dfb[j] == "1" ? console.log() : delete days[5] ;
                    break;
            }

        }




        days = days.filter(Boolean);
        let myVar3 = days.join(", ")

        for (let i = 0; i < days.length; i++) {
            
        }

        console.log(myVar3)
        switch (days.length){
            case 7:
             myVar3 = "Every day";
             break;
            case 0:
                myVar3 = "None";
        }


        alarmConstainer.innerHTML += `                
        <div class="alarm__box" id="alarmConstainer" data-alarmIndex="${i}" onclick="displayEditAlarm(${i})">
            <div class="alarm__box__constent__posicion">
                <div class="alarm__box__content alarm__box__edit--content">
                    <div class="alarm__box__content--day">
                        <div class="icon">
                        <svg width="7" height="7" viewBox="0 0 7 7" fill="none" xmlns="http://www.w3.org/2000/svg">
                            <circle cx="3.5" cy="3.5" r="3.5" fill="#007AFF"/>
                        </svg>  
                    </div>
                    <div class="content">
                        <span>${myVar3}</span>
                    </div>
                </div>
                <div class="alarm__box__content--time">
                    <span>${json.alarm[i].hour}:${json.alarm[i].min}</span>
                </div>
                <div class="alarm__box__content--name">
                    <span>${json.alarm[i].name}</span>
                </div>
            </div>
            <div class="alarm__box__switch">
                <div class="switch__static alarm__box__switch--switch">
                    <div class="switch__static--posicion">
                        <div>
                            <input type="checkbox" onclick="postAlarmStatus(${i})" name="alarmSwitch" id="alarmSwitch${i}" ${state}>
                            <label for="alarmSwitch${i}" class="switch__static__label">
                                <span class="circle"></span>
                            </label>
                        </div>
                    </div>
                </div>
            </div>
            </div>
            <div class="alarm__box__action" id="alarmBoxAction" >
                <div class="btn alarm__box__action--btn">
                    <button onclick="removeAlarm(${i})">Delete alarm</button>
                </div>
            </div>

    </div>`

    }
    
}




const inputSelectbrightness = document.querySelectorAll('input[name="brightness"]')
const inputSriderbrightness = document.querySelector('#brightness')
const inputBrightnessContainer = document.querySelector('.brightness__slider')


inputSelectbrightness.forEach(input => {
    input.addEventListener('input', () => {
        if(input.value == "auto"){
            inputBrightnessContainer.classList.add('disabel')
            inputSriderbrightness.disabled = true;
        }else{
            inputBrightnessContainer.classList.remove('disabel')
            inputSriderbrightness.disabled = false
        }
    })
})

const boxCard = document.querySelectorAll('.box__card')

boxCard.forEach(item => {
    item.addEventListener('click', () => {
        item.querySelector('.box__card__content--arrow').classList.toggle("box__card__open")
        if(item.parentElement.querySelector('.box__content').style.height != "0px"){
            item.parentElement.querySelector('.box__content').style.height = '0px'
        }else{
            item.parentElement.querySelector('.box__content').style.height = item.parentElement.querySelector('.box__content').scrollHeight + 'px'
        }
    })
})


// -------------------HANDLER FORM------------------------------------------


const networkHandler = () => {
    const networkName = document.querySelector('#networkName').value
    const networkPass = document.querySelector('#networkPass').value

    const address = ipInputeToArray('networkIP')
    const gateway = ipInputeToArray('networkGateway')
    const mask = ipInputeToArray('networkMask')

    if(networkName == ""){
        console.log("error")
    }else{
        const data = {
            name: networkName,
            staticIpEnable: networkStaticIPSwitch.checked,
            pass: networkPass,
            address: address,
            gateway: gateway,
            mask: mask
        }

        postData('/set/network', data)
            .then(data => {
                if(data.status == 200){
                    messageBox("ok")
                    alert("To apply the changes you need to reset the device in the device tab")
                  }else{
                    messageBox("error")
                  }
            });
    }

}
// ---------------Mqtt---------------
const mqqttUser = document.querySelector('input[name="MqqttUser"]')
const mqqttPass = document.querySelector('input[name="MqqttPass"]')
const mqttTopic = document.querySelector('input[name="mqttTopic"]')
const mqttSwitch = document.querySelector('input[name="mqtt__switch"]');

const mqttHandling  = () => {
    const mqttIP1 = document.querySelector('input[name="mqttip1"]')
    const mqttIP2 = document.querySelector('input[name="mqttip2"]')
    const mqttIP3 = document.querySelector('input[name="mqttip3"]')
    const mqttIP4 = document.querySelector('input[name="mqttip4"]')
    const mqttIP = mqttIP1.value + "." + mqttIP2.value + "."+ mqttIP3.value + "."+ mqttIP4.value
    let mqqttEnable = 0
    
    if(mqttSwitch.checked){
        mqqttEnable = 1
    }

    let data = {
        mqttIP: mqttIP,
        mqqttUser: mqqttUser.value,
        mqqttPass: mqqttPass.value,
        mqttTopic: mqttTopic.value,
        mqqttEnable: mqqttEnable
    }

    postData('/set/mqtt', data)
    .then(data => {
      if(data.status == 200){
        messageBox("ok")
        alert("To apply the changes you need to reset the device in the device tab")
      }else{
        messageBox("error")
      }
    });
} 

// ---------------Weather---------------

const watherApiInput = document.querySelector('input[name="weatherKey"]')
const weatherCityInput = document.querySelector('input[name="weatherCity"]')
const weatherUnit = document.querySelectorAll('input[name="weatherUnit"]')

const weatherHandling = () => {
    const data = {
        api:watherApiInput.value,
        city: weatherCityInput.value,
        fahrenheit: weatherUnit[1].checked ? true : false
    }
    
    console.log(data)

    postData('/set/weather', data)
    .then(data => {
        if(data.status == 200){
            messageBox("ok")
            alert("To apply the changes you need to reset the device in the device tab")
        }else{
            messageBox("error")
        }
    });
}


// ---------------Temperature---------------

const tempOutputHandling = document.querySelector('#temperature')
const tempUnit = document.querySelectorAll('input[name="tempUnit"]')

const temepratureHandling = () => {

    let data = {
        value: parseInt(tempOutputHandling.value.replace('+', '')),
        fahrenheit: tempUnit[1].checked ? true : false
    };

    postData('/set/temperature', data)
    .then(data => {
        if(data.status == 200){
            messageBox("ok")
        }else{
            messageBox("error")
        }
    });
}

// ---------------time zone---------------


const timeZoneHandling  = () => {
    const zoneValue = inputUTCZoneTime.value
    const extractNumbersFromString = zoneValue.match(/-?\d+/g).map(Number);

    let data = {
        server: inputZoneTime.value,
        UTC: extractNumbersFromString[0]
    };
    console.log(data)

    postData('/set/timezone', data)
    .then(data => {
        if(data.status == 200){
            messageBox("ok")
            alert("To apply the changes you need to reset the device in the device tab")
        }else{
            messageBox("error")
        }
    });
} 


// ---------------Brighnes---------------

const brightnessHandling  = () => {
    let data = {
        value: 0,
        auto: true
    };

    for (const radio of inputSelectbrightness) {
        if(radio.checked){
            if(radio.value == "auto"){
                data.auto = true
            }else{
                data.auto = false
                data.value = inputSriderbrightness.value
            }
        }
    }

    postData('/set/brightness', data)
    .then(data => {
        if(data){
            inputSriderbrightness.value = data.value
            messageBox("ok")
        }else{
            messageBox("error") 
        }

    });
} 

// ---------------NightMode---------------
const nightModeFromHours = document.querySelector('#nightModeFromHours')
const nightModeFromMin = document.querySelector('#nightModeFromMin')

const nightModeToHours = document.querySelector('#nightModeToHours')
const nightModetoMin = document.querySelector('#nightModetoMin')

const nightModeSwitch = document.querySelector('#nightModeSwitch')


const valideteNightModeFoucusout = (input) => {
    if(input.value < 10 && input.value.length < 2){
        input.value = "0" + input.value
    }
}
const valideteNightModeInputHour = (input) => {
    if(input.value > 23){
        input.value = 0
    }
    if(input.value.length > 2){
        input.value = 00
    }
}

const valideteNightModeInputMin = (input) => {
    if(input.value > 59){
        input.value = 0
    }
    if(input.value.length > 2){
        input.value = 00
    }
}

[nightModeFromHours, nightModeToHours].forEach((input) => {
    input.addEventListener('input', (e) => valideteNightModeInputHour(e.target))
    input.addEventListener('focusout', (e) => valideteNightModeFoucusout(e.target))
});

[nightModeFromMin, nightModetoMin].forEach((input) => {
    input.addEventListener('input', (e) => valideteNightModeInputMin(e.target))
    input.addEventListener('focusout', (e) => valideteNightModeFoucusout(e.target))
});



const nightModeHandling  = () => {
    let data = {
        enable: nightModeSwitch.checked,
        fromHour: nightModeFromHours.value,
        fromMin: nightModeFromMin.value,
        toHour: nightModeToHours.value,
        toMin: nightModetoMin.value,
    };
    console.log(data)
    
    postData('/set/nightmode', data)
    .then(data => {
        if(data.status == 200){
            messageBox("ok")
        }else{
            messageBox("error")
        }
    });
} 


// ------------------display Scroling text------------------

const displayScrollTestHandling  = () => {
    const inputScrollText = document.querySelector('input[name="sendText"]')
    const scrolingSpeed = document.querySelector('#repetitions')
        const data = {
            text: inputScrollText.value,
            repeat: scrolingSpeed.value
        }
        
    if(data.text != ""){
        postData('/display/text', data)
        .then(data => {
            console.log(data); // JSON data parsed by `data.json()` call
        });
    }

} 


// ---------------Alarm---------------



const alarmAddHandler = () => {
    let alarmDay = [0,0,0,0,0,0,0]
    console.log(alarmAddHours.value)
    console.log(alarmAddMin.value)
    const alarmAddDay = document.querySelectorAll('input[name="alarmAddDay"]')
    for (let i = 0; i < 7; i++) {
        if(alarmAddDay[i].checked){
            alarmDay[i] = 1
        }else{
            alarmDay[i] = 0
        }
    }
    alarmAddCloseCard()
    const alarmName = document.querySelector('#alarmAddName').value
    const alarmDayToSend = alarmDay[6] + "" + alarmDay[0] + "" + alarmDay[1] + "" + alarmDay[2] + "" + alarmDay[3] + "" + alarmDay[4] + "" + alarmDay[5] + ""
    console.log(alarmDayToSend)
    const data = {
        state: "1",
        hour: alarmAddHours.value,
        min: alarmAddMin.value,
        name: alarmName,
        day: alarmDayToSend
    }
    console.log(data)
    postData('/alarm/add', data)
    .then(data => {
      console.log(data);
    });
    getAlarmList();
}

const postAlarmStatus = async (index) => {
    const data = {
        index: index
    }

    postData('/alarm/update', data)
    .then(data => {
        if(data.state == "1"){
            document.querySelector(`#alarmSwitch${index}`).checked = true
        }
        else{
            document.querySelector(`#alarmSwitch${index}`).checked = false
        }
    });
    
}

const removeAlarm = (index) => {
    console.log(index)
    const alarmBox = document.querySelector(`[data-alarmIndex="${index}"]`)
    const data = {
        index: index
    }

    postData('/alarm/remove', data)
        .then(data => {
            if(data.status == "200"){
                alarmBox.classList.add("alarm__box--slideOut")
                return new Promise(resolve => { 
                    setTimeout(() => {
                        alarmBox.hidden = true
                        getAlarmList();
                        resolve();
                    }, 1000)
                });
            }
        })

}

const getAlarmList = async () => {
    const alarmConstainer = document.querySelector('#alarma__box__constainer')


    await fetch('/alarm/list')
    .then(response => response.json())
        .then(data => alarmJSON = JSON.parse(data.alarm));
        
        
        
    if(parseInt(alarmJSON.alarmNum) == 1){
        alarmConstainer.innerHTML = `
        <div id="alarma__box__constainer">
            <div class="alarm__box--none">
                <div>
                    <span>No alarm</span>
                    <p>click “+” to add a new alarm</p>
                </div>
            </div>
        </div>`
    }else{
        await displayAlarmCard(alarmJSON)
    }


}

// ----------Boot task------------------
let version;
const autoStartTask = async () => {
    let jsons;
    await fetch('/data')
        .then(response => response.json())
            .then(data => jsons = data);


    if(jsons.brightness){
        if(jsons.brightness.auto){
            inputSriderbrightness.disabled = true;
            inputBrightnessContainer.classList.add('disabel')
            inputSelectbrightness[0].checked = true;
            inputSriderbrightness.value = jsons.brightness.value;
        }else{
            inputSelectbrightness[1].checked = true;
            inputSriderbrightness.value = jsons.brightness.value;
        }
        rageUpdate(1)
        setValue()
    }
    if(jsons.nightMode){
        nightModeSwitch.checked = jsons.nightMode.enable
        nightModeFromHours.value = jsons.nightMode.from[0]
        nightModeFromMin.value = jsons.nightMode.from[1]

        nightModeToHours.value = jsons.nightMode.to[0]
        nightModetoMin.value = jsons.nightMode.to[1]
    }

    if(jsons.ntpIP){
        inputZoneTime.value = jsons.ntpIP
        inputeText()
    }
    if(jsons.timeZone){
        if (parseInt(jsons.timeZone) >= 0) {
            inputUTCZoneTime.value = "+" + jsons.timeZone + " h"
        }else{
            inputUTCZoneTime.value = jsons.timeZone + " h"
        }
    }
    if(jsons.temperature){
        if(jsons.temperature.value >= 0){
            tempOutputHandling.value = "+" + jsons.temperature.value
        }
        if(!jsons.temperature.fahrenheit){
            tempUnit[0].checked = true
        }else{
            tempUnit[1].checked = true
        }
    }
    if(jsons.mqtt[0]){
        const x =  jsons.mqtt[0]
        const myArr = x.split(".")
        for (let i = 0; i < 4; i++) {
          document.querySelector(`input[name="mqttip${i + 1}"]`).value = myArr[i]
        }
    }

    if(jsons.mqtt[1]){
        mqqttUser.value = jsons.mqtt[1]
        console.log(mqqttUser.value)
    }
    if(jsons.mqtt[2]){
        mqttTopic.value = jsons.mqtt[2]
    }
    if(jsons.mqtt[3]){
        if(jsons.mqtt[3] == 1){
            mqttSwitch.checked = true
        }else{
            mqttSwitch.checked = false
        }

    }
    if(jsons.weather){
        weatherCityInput.value = jsons.weather.city
        if(!jsons.weather.fahrenheit){
            weatherUnit[0].checked = true
        }else{
            weatherUnit[1].checked = true
        }
    }

    if(jsons.firmware){
        document.querySelector('#firmwareVersion').innerHTML = jsons.firmware
        version = jsons.firmware
    }
    if(jsons.wifi[0]){
        document.querySelector('#networkName').value = jsons.wifi[0].ssid;
        if(jsons.wifi[0].enableStaticIp == "true"){
            networkStaticIPSwitch.checked = true
            for (let i = 0; i < 4; i++) {
                document.querySelector(`input[name='networkIP${i}']`).value = jsons.wifi[0].staticIP[i]
                document.querySelector(`input[name='networkGateway${i}']`).value = jsons.wifi[0].gateway[i]
                document.querySelector(`input[name='networkMask${i}']`).value = jsons.wifi[0].subnet[i]
            }
        }
        
       
    }



    inputeText()

}

// --------------------FIRMWARE UPDATE---------------------------

const inputeFirmwareFile = document.querySelector(".firmware__drop__section__input"),
  dropZoneElement = inputeFirmwareFile.closest(".firmware__drop__section");

const firmwareInputeFile = () => {
  inputeFirmwareFile.addEventListener("input", (e) => {
    updateFirmwareValidation(e);
  });

  inputeFirmwareFile.addEventListener("dragover", (e) => {
    e.preventDefault();
    dropZoneElement.classList.add("firmware__drop__section--over");
  });

  ["dragleave", "dragend"].forEach((type) => {
    dropZoneElement.addEventListener(type, (e) => {
      dropZoneElement.classList.remove("firmware__drop__section--over");
    });
  });

  inputeFirmwareFile.addEventListener("drop", (e) => {
    e.preventDefault();
    if (e.dataTransfer.files.length) {
      inputeFirmwareFile.files = e.dataTransfer.files;
      updateFirmwareValidation(e)
    }
    dropZoneElement.classList.remove("firmware__drop__section--over");
  });
}

const updateFirmwareValidation = (e) => {
  if(e.target.files.length){
    console.log(e.target.files.length)
    if(e.target.files[0].name.split('.').pop() != "bin"){
      console.log('Wysłano plik')
      dropZoneElement.classList.remove("firmware__drop__section--ok")
      dropZoneElement.classList.add("firmware__drop__section--error")
      document.querySelector('#firmwareDropMessage').innerHTML = `Only files with the ".bin" extension`
      inputeFirmwareFile.value = null
    }else{
      dropZoneElement.classList.add("firmware__drop__section--ok")
      dropZoneElement.classList.remove("firmware__drop__section--error")
      console.log(e.target.files)
      document.querySelector('#firmwareDropMessage').innerHTML = `file: ${e.target.files[0].name}`
    }
  }
}
 
const firmwareHandlerSend = () => {
  if(inputeFirmwareFile.files.length){
    postFile("/update" ,inputeFirmwareFile.files[0])
  }
}


const postFile = async (url, file) => {
    const formData = new FormData()
    formData.append('myFile', file)
    fetch(url, {
        method: 'POST',
        body: formData
      })
}
  


firmwareInputeFile()



// ----------fetch API------------------


const postData = async (url = '', data = {}) => {
    const response = await fetch(url, {
        method: 'POST',
        mode: 'cors', 
        cache: 'no-cache', 
        credentials: 'same-origin', 
        headers: {
          'Content-Type': 'application/json'
          // 'Content-Type': 'application/x-www-form-urlencoded',
        },
        redirect: 'follow', 
        referrerPolicy: 'no-referrer',
        body: JSON.stringify(data)
    });
    return response.json()
}

// -----calling ----------

autoStartTask()
getAlarmList()
temepratureInpute()
timeZoneUTCInpute()
inputeText()


)=====";