#ifndef SUBPROCESSBROWSER_H
#define SUBPROCESSBROWSER_H
#include "engine_global.h"

#include "ibrowser.h"
#include "iprocesscomunicatorfactory.h"

namespace BrowserAutomationStudioFramework
{

    class ENGINESHARED_EXPORT SubprocessBrowser : public IBrowser
    {
        Q_OBJECT
        IWorker *Worker;
        IWorker *LastInjectedWorker;
        INetworkAccessManagerFactory *NetworkAccessManagerFactory;
        INetworkAccessManager *NetworkAccessManager;
        IProcessComunicatorFactory *ProcessComunicatorFactory;
        IProcessComunicator *ProcessComunicator;

    public:

        explicit SubprocessBrowser(QObject *parent = 0);

    public slots:
        virtual void SetNetworkAccessManagerFactory(INetworkAccessManagerFactory *NetworkAccessManagerFactory);
        void SetProcessComunicatorFactory(IProcessComunicatorFactory *ProcessComunicatorFactory);
        virtual void LoadPage(const QString& url, const QString& callback);
        virtual void SetUserAgent(const QString& agent, const QString& callback);
        virtual void GetCookiesForUrl(const QString& url, const QString& callback);
        virtual void SaveCookies(const QString& callback);
        virtual void RestoreCookies(const QString& cookies, const QString& callback);
        virtual IWebElement* GetRootElement();
        virtual void GetUrl(const QString& callback);
        virtual void CreateNewBrowser(bool ForseNewBrowserCreation, const QString& callback);
        virtual INetworkAccessManager* GetNetworkAccessManager();
        virtual void SetScriptResources(IScriptResources* ScriptResources);
        virtual IScriptResources* GetScriptResources();
        virtual void SetWorker(IWorker* Worker);
        virtual IWorker* GetWorker();
        virtual void SetOpenFileName(const QString & OpenFileName, const QString& callback);
        virtual void SetPromptResult(const QString & Text, const QString& callback);
        virtual void SetHttpAuthResult(const QString & Login, const QString & Password, const QString& callback);
        virtual void MouseClickInstant(int x, int y);
        virtual void MouseClick(int x, int y, const QString& callback);
        virtual void MouseMove(int x, int y, const QString& callback);
        virtual void Resize(int x, int y, const QString& callback);
        virtual void Reset(const QString& callback);
        virtual void Jquery(const QString& callback);
        virtual void OptimizeMemory(const QString& callback);
        virtual void WaitCode(const QString& callback);
        virtual void StartSection(const QString& Name, int Id, const QString& callback);
        virtual void Scroll(int x, int y, const QString& callback);
        virtual void Render(int x, int y, int width, int height, const QString& callback);
        void MarkBeforeReset();
        void MarkAfterReset();

        virtual void OnSupend();
    signals:
        void ProcessCreated(IProcessComunicator *Communicator);
        void Loaded();
        void GetUrl();
        void SetUserAgent();
        void GetCookiesForUrl();
        void SaveCookies();
        void RestoreCookies();
        void SetOpenFileName();
        void SetHttpAuthResult();
        void SetPromptResult();
        void MouseClick();
        void MouseMove();
        void Resize();
        void Reset();
        void Scroll();
        void Render();
        void Jquery();
        void OptimizeMemory();
        void WaitCode();

    private slots:
        void Received(const QString& value);
        void WorkerStopped();
    };
}
#endif // SUBPROCESSBROWSER_H

